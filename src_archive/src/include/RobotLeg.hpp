//
// Created by OEM on 05.10.2022.
//

#ifndef ZEBULON05_ROBOTLEG_HPP
#define ZEBULON05_ROBOTLEG_HPP

class RobotLeg {
private:
    const unsigned int num_of_servos = 3;
    const unsigned int step_interpolation = 2;

    virtual void do_step(int step_height, int step_length);

};


#endif //ZEBULON05_ROBOTLEG_HPP
