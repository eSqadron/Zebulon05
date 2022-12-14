from cmath import *
from time import sleep

import serial
from sys import version_info

PY2 = version_info[0] == 2  # Running Python 2.x?


#
# ---------------------------
# Maestro Servo Controller
# ---------------------------
#
# Support for the Pololu Maestro line of servo controllers
#
# Steven Jacobs -- Aug 2013
# https://github.com/FRC4564/Maestro/
#
# These functions provide access to many of the Maestro's capabilities using the
# Pololu serial protocol
#
class Controller:
    # When connected via USB, the Maestro creates two virtual serial ports
    # /dev/ttyACM0 for commands and /dev/ttyACM1 for communications.
    # Be sure the Maestro is configured for "USB Dual Port" serial mode.
    # "USB Chained Mode" may work as well, but hasn't been tested.
    #
    # Pololu protocol allows for multiple Maestros to be connected to a single
    # serial port. Each connected device is then indexed by number.
    # This device number defaults to 0x0C (or 12 in decimal), which this module
    # assumes.  If two or more controllers are connected to different serial
    # ports, or you are using a Windows OS, you can provide the tty port.  For
    # example, '/dev/ttyACM2' or for Windows, something like 'COM3'.
    def __init__(self, ttyStr='/dev/ttyACM0', device=0x0c):
        # Open the command port
        self.usb = serial.Serial(ttyStr)
        # Command lead-in and device number are sent for each Pololu serial command.
        self.PololuCmd = chr(0xaa) + chr(device)
        # Track target position for each servo. The function isMoving() will
        # use the Target vs Current servo position to determine if movement is
        # occuring.  Upto 24 servos on a Maestro, (0-23). Targets start at 0.
        self.Targets = [0] * 24
        # Servo minimum and maximum targets can be restricted to protect components.
        self.Mins = [0] * 24
        self.Maxs = [0] * 24

    # Cleanup by closing USB serial port
    def close(self):
        self.usb.close()

    # Send a Pololu command out the serial port
    def sendCmd(self, cmd):
        cmdStr = self.PololuCmd + cmd
        if PY2:
            self.usb.write(cmdStr)
        else:
            self.usb.write(bytes(cmdStr, 'latin-1'))

    # Set channels min and max value range.  Use this as a safety to protect
    # from accidentally moving outside known safe parameters. A setting of 0
    # allows unrestricted movement.
    #
    # ***Note that the Maestro itself is configured to limit the range of servo travel
    # which has precedence over these values.  Use the Maestro Control Center to configure
    # ranges that are saved to the controller.  Use setRange for software controllable ranges.
    def setRange(self, chan, min, max):
        self.Mins[chan] = min
        self.Maxs[chan] = max

    # Return Minimum channel range value
    def getMin(self, chan):
        return self.Mins[chan]

    # Return Maximum channel range value
    def getMax(self, chan):
        return self.Maxs[chan]

    # Set channel to a specified target value.  Servo will begin moving based
    # on Speed and Acceleration parameters previously set.
    # Target values will be constrained within Min and Max range, if set.
    # For servos, target represents the pulse width in of quarter-microseconds
    # Servo center is at 1500 microseconds, or 6000 quarter-microseconds
    # Typcially valid servo range is 3000 to 9000 quarter-microseconds
    # If channel is configured for digital output, values < 6000 = Low ouput
    def setTarget(self, chan, target):
        # if Min is defined and Target is below, force to Min
        if self.Mins[chan] > 0 and target < self.Mins[chan]:
            target = self.Mins[chan]
        # if Max is defined and Target is above, force to Max
        if self.Maxs[chan] > 0 and target > self.Maxs[chan]:
            target = self.Maxs[chan]
        #    
        lsb = target & 0x7f  # 7 bits for least significant byte
        msb = (target >> 7) & 0x7f  # shift 7 and take next 7 bits for msb
        cmd = chr(0x04) + chr(chan) + chr(lsb) + chr(msb)
        self.sendCmd(cmd)
        # Record Target value
        self.Targets[chan] = target

    # Set speed of channel
    # Speed is measured as 0.25microseconds/10milliseconds
    # For the standard 1ms pulse width change to move a servo between extremes, a speed
    # of 1 will take 1 minute, and a speed of 60 would take 1 second.
    # Speed of 0 is unrestricted.
    def setSpeed(self, chan, speed):
        lsb = speed & 0x7f  # 7 bits for least significant byte
        msb = (speed >> 7) & 0x7f  # shift 7 and take next 7 bits for msb
        cmd = chr(0x07) + chr(chan) + chr(lsb) + chr(msb)
        self.sendCmd(cmd)

    # Set acceleration of channel
    # This provide soft starts and finishes when servo moves to target position.
    # Valid values are from 0 to 255. 0=unrestricted, 1 is slowest start.
    # A value of 1 will take the servo about 3s to move between 1ms to 2ms range.
    def setAccel(self, chan, accel):
        lsb = accel & 0x7f  # 7 bits for least significant byte
        msb = (accel >> 7) & 0x7f  # shift 7 and take next 7 bits for msb
        cmd = chr(0x09) + chr(chan) + chr(lsb) + chr(msb)
        self.sendCmd(cmd)

    # Get the current position of the device on the specified channel
    # The result is returned in a measure of quarter-microseconds, which mirrors
    # the Target parameter of setTarget.
    # This is not reading the true servo position, but the last target position sent
    # to the servo. If the Speed is set to below the top speed of the servo, then
    # the position result will align well with the acutal servo position, assuming
    # it is not stalled or slowed.
    def getPosition(self, chan):
        cmd = chr(0x10) + chr(chan)
        self.sendCmd(cmd)
        lsb = ord(self.usb.read())
        msb = ord(self.usb.read())
        return (msb << 8) + lsb

    # Test to see if a servo has reached the set target position.  This only provides
    # useful results if the Speed parameter is set slower than the maximum speed of
    # the servo.  Servo range must be defined first using setRange. See setRange comment.
    #
    # ***Note if target position goes outside of Maestro's allowable range for the
    # channel, then the target can never be reached, so it will appear to always be
    # moving to the target.  
    def isMoving(self, chan):
        if self.Targets[chan] > 0:
            if self.getPosition(chan) != self.Targets[chan]:
                return True
        return False

    # Have all servo outputs reached their targets? This is useful only if Speed and/or
    # Acceleration have been set on one or more of the channels. Returns True or False.
    # Not available with Micro Maestro.
    def getMovingState(self):
        cmd = chr(0x13)
        self.sendCmd(cmd)
        if self.usb.read() == chr(0):
            return False
        else:
            return True

    # Run a Maestro Script subroutine in the currently active script. Scripts can
    # have multiple subroutines, which get numbered sequentially from 0 on up. Code your
    # Maestro subroutine to either infinitely loop, or just end (return is not valid).
    def runScriptSub(self, subNumber):
        cmd = chr(0x27) + chr(subNumber)
        # can pass a param with command 0x28
        # cmd = chr(0x28) + chr(subNumber) + chr(lsb) + chr(msb)
        self.sendCmd(cmd)

    # Stop the current Maestro Script
    def stopScript(self):
        cmd = chr(0x24)
        self.sendCmd(cmd)


h_1_ = 40
a_1_ = 55
a_2_ = 125
a_3_ = 180


def rad2qns1(rad):
    temp = (((rad * 980.75) / (pi / 2)) + 1554.25) * 4
    return temp


def rad2qns2(rad):
    temp = (((rad * 1000) / (pi / 2)) + 1500) * 4
    return temp


# def forward_kinematics(const std::array<float, 3> angles_deg){
#     //std::array<float, 3> angles_deg = {quarter_nano_seconds_to_rad(angles[0]), quarter_nano_seconds_to_rad(angles[1]), quarter_nano_seconds_to_rad(angles[2])};
#     std::array<float, 3> result;
#     float a_temp = a_2_ * cos(angles_deg[1]) + a_3_ * cos(angles_deg[2] - angles_deg[1]) + a_1_;
#     result[0] = a_temp * cos(angles_deg[0]);
#     result[1] = a_temp * sin(angles_deg[0]);
#     result[2] = a_2_ * sin(angles_deg[1]) - a_3_ * sin(angles_deg[2] - angles_deg[1]);
#
#     return result;
# }

def inverse_kinematics(xyz_pos):
    result_rad = [0, 0, 0]
    x = xyz_pos[0]
    y = xyz_pos[1]
    z = xyz_pos[2]
    result_rad[0] = atan(y / x).real
    result_rad[2] = acos((pow(x - a_1_, 2) + pow(h_1_ + z, 2) - pow(a_2_, 2) - pow(a_3_, 2)) / (2 * a_2_ * a_3_)).real
    p1 = atan((h_1_ + z) / (x - a_1_)).real
    p2 = atan(a_3_ * sin(result_rad[2]) / (a_2_ + a_3_ * cos(result_rad[2]))).real

    print("p1: ", p1, "p2: ", p2)
    print(a_2_, a_3_ * cos(result_rad[2]))

    theta_2_g = acos(-a_2_/a_3_).real
    p_2_g = atan(a_3_ * sin(theta_2_g) / (a_2_ + a_3_ * cos(theta_2_g))).real
    print("0_2_g: ", theta_2_g, "p_2_g: ", p_2_g)

    result_rad[1] = (p1 + 2 * p_2_g + p2 if(result_rad[2] > theta_2_g) else p1 + p2)

    print(result_rad[1])

    print([i.real * 180 / pi for i in result_rad])

    return result_rad


def move_leg_xyz(x, y, z):
    inv_k = inverse_kinematics([x, y, z])
    # temp_out_buffer_ = inv_k[1]
    # temp_out_buffer2_ = rad2qns(temp_out_buffer_)

    angs_r = [k.real for k in inv_k]
    alfa = angs_r[1]
    beta = angs_r[2] - angs_r[1]
    print(x, z)
    print(int((cos(alfa) * a_2_ + cos(beta) * a_3_ + a_1_).real),
          -h_1_ + int((sin(alfa) * a_2_ - sin(beta) * a_3_).real))

    inv_k[1] = inv_k[1] - (35 * pi / 180)
    inv_k[2] = inv_k[2] - (70 * pi / 180)
    # print(inv_k)

    return [rad2qns2(inv_k[0]), rad2qns2(inv_k[1]), rad2qns2(inv_k[2])]


def actually_move_leg(x, y, z, s=0):
    qns = move_leg_xyz(x, y, z)
    for i in range(s * 3, s * 3 + 3):
        t = int(qns[i % 3].real)
        # t = int(move_leg_xyz(a_1_ + a_2_, 0, -40)[i].real)
        maestro_controller.setTarget(i, t)
        print()


if __name__ == '__main__':
    maestro_controller = Controller('COM4')
    # for i in range(3):
    # actually_move_leg(150, 0, -50)
    # actually_move_leg(a_1_ + a_2_ + a_3_, 0, -50)
    # for i in range(50):
    #     actually_move_leg(135+a_1_-i, 0, -40)
    #     sleep(1)
    for i in range(3):
        actually_move_leg(150, 0, -100, i)

    leg_pos_ = [pi * 60 / 180, pi, pi * 300 / 180]
    step_len_ = 100
    step_height = 60
    leg_no = 0
    delta_y = (step_len_ * sin(0 - leg_pos_[leg_no])).real
    delta_x = (step_len_ * cos(0 - leg_pos_[leg_no])).real

    actually_move_leg(150, 0, -100)
    sleep(2)

    actually_move_leg(150 + delta_x/2, 0 + delta_y/2, -100 + step_height)
    sleep(2)
    actually_move_leg(150 + delta_x, 0 + delta_y, -100)
    sleep(5)
    actually_move_leg(150, 0, -100)

    # for i in range(3):
    #     actually_move_leg(a_1_+a_2_+a_3_, 0, -50, i)

    # sleep(2)

    # maestro_controller.setTarget(0, int(rad2qns1(0)))
    # maestro_controller.setTarget(1, int(rad2qns(pi/2)))
    # maestro_controller.setTarget(2, int(rad2qns(pi/2)))