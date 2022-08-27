#include <cmath>
#include "../include/RobotLeg.hpp"


std::array<int, 3> RobotLeg::forward_kinematics(const std::array<int, 3> angles) const{
    std::array<int, 3> result{};
    int temp_third_len = (joint_distances[2] * cos(angles[1])) + (joint_distances[3] * cos(angles[2] - angles[1])) + joint_distances[1];
    result[0] = joint_distances[0] +  temp_third_len * cos(angles[0]); // X
    result[1] = temp_third_len * sin(angles[0]); // Y
    result[2] = h0 - h1 + joint_distances[2] * sin(angles[1]) - joint_distances[3] * sin(angles[2] - angles[1]); // Z
    return result;
}

void RobotLeg::set_servo(ServoJoint* new_servo, unsigned int servo_num){
    if(servo_num == 0){
        this->servo0 = new_servo;
    }
    if(servo_num == 1){
        this->servo1 = new_servo;
    }
    if(servo_num == 2){
        this->servo2 = new_servo;
    }
}


std::array<int, 3> RobotLeg::get_current_angles() const{
    return std::array<int, 3>{{static_cast<int>(this->servo0->get_servo_angle()), static_cast<int>(this->servo1->get_servo_angle()), static_cast<int>(this->servo2->get_servo_angle())}};
}

std::array<int, 3> RobotLeg::get_current_endpoint_pos() const{
    return this->forward_kinematics(this->get_current_angles());
}

std::array<int, 3> RobotLeg::inverse_kinematics(const std::array<int, 3> endpoint_position) {


    return std::array<int, 3>();
}

void RobotLeg::do_step(const int step_length, const int step_height, const int step_angle, const unsigned int interpolation) {
    if(step_angle < -90 or step_angle > 90){
        throw std::range_error("angle out of -90 +90 angle range");
    }

    if(interpolation == 0){
        std::array<int, 3> zero_pos = get_current_endpoint_pos();
        std::array<int, 3> desired_pos{static_cast<int>(zero_pos[0] + step_length/2.0 * cos(step_angle)), static_cast<int>(zero_pos[1] + step_length/2.0 * sin(step_angle)), zero_pos[2] + step_height};
        move_to_pos(desired_pos);
        std::array<int, 3> temp_pos = get_current_endpoint_pos();
        while(temp_pos[0] != desired_pos[0] and temp_pos[1] != desired_pos[1] and temp_pos[2] != desired_pos[2]){
            temp_pos = get_current_endpoint_pos();
        }

        desired_pos = {static_cast<int>(temp_pos[0] + step_length/2.0 * cos(step_angle)), static_cast<int>(temp_pos[1] + step_length/2.0 * sin(step_angle)), zero_pos[2]};
        move_to_pos(desired_pos);

        while(temp_pos[0] != desired_pos[0] and temp_pos[1] != desired_pos[1] and temp_pos[2] != desired_pos[2]){
            temp_pos = get_current_endpoint_pos();
        }

    }
    else{
        throw std::range_error("interpolation out of implemented range~!");
    }
}

void RobotLeg::move_to_pos(const std::array<int, 3> endpoint_position) {
    std::array<int, num_of_servos> desired_angles = inverse_kinematics(endpoint_position);

    for(int i =0; i< num_of_servos; i++){
        servos[i]->move_servo(desired_angles[i]);
    }

}
