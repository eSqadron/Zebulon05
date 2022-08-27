#include "RobotLeg.hpp"
#include <iostream>

class SimServo: public ServoJoint{
    double current_pos = 0;
    void move_servo(double target) override{
        current_pos = target;
    }
    double get_servo_angle() override{
        return current_pos;
    }
};

int main(){
    SimServo serv1;
    SimServo serv2;
    SimServo serv3;

    RobotLeg leg;
    leg.set_servo(&serv1, 0);
    leg.set_servo(&serv2, 1);
    leg.set_servo(&serv3, 2);

    std::cout << "hello";
}