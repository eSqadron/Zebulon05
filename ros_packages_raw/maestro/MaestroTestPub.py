import rclpy
from rclpy.node import Node

from std_msgs.msg import String

from maestro_interfaces.msg import MaestroTarget, CurrentPositions


class MaestroTestPub(Node):
    def __init__(self):
        super().__init__('maestro_test_pub')
        self.new_target = self.create_publisher(
            MaestroTarget,
            'maestro_target',
            2)

        timer_period = 0.5  # seconds
        self.timer = self.create_timer(
            timer_period,
            self.new_target)

        self.target_channel = 0
        self.target_target = 0
        self.target_speed = 0
        self.target_accel = 0

        self.sweep_i = 496 * 4
        self.sweep_dir = 1

        self.test_mode = "sweep_over_channel_0"

    def pos_publisher_timer_callback(self):
        msg = MaestroTarget()

        if self.test_mode == "manual":
            msg.channel = self.target_channel
            msg.target_ang = self.target_target
            msg.speed = self.target_speed
            msg.acceleration = self.target_accel
        elif self.test_mode == "sweep_over_channel_0":
            msg.channel = 0
            msg.target_ang = self.sweep_i
            msg.speed = 0
            msg.acceleration = 0

            self.sweep_i += self.sweep_dir

            if self.sweep_i == 2496 * 4 + 1:
                self.sweep_dir = -1

            if self.sweep_i == 496 * 4 - 1:
                self.sweep_dir = 1

        self.current_pos_publisher.publish(msg)

    def set_new_test_target(self, channel: int, target: int, speed=0, accel=0):
        self.target_channel = channel
        self.target_target = target
        self.target_speed = speed
        self.target_accel = accel

    def set_mode(self, mode: str):
        self.test_mode = mode
