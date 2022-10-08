//
// Created by OEM on 07.10.2022.
//

#include "../include/RobotLeg/RobotLegRos.hpp"


void RobotLegRos::do_step(int step_length, int step_height){
        this->get_servos_to_pos(std::array<unsigned int, 3>({2496 * 4, 2496 * 4, 2496 * 4 * step_length * step_height}));
        this->get_servos_to_pos(std::array<unsigned int, 3>({496 * 4, 496 * 4, 496 * 4 * step_length * step_height}));
}

void RobotLegRos::get_servos_to_pos(std::array<unsigned int, 3> new_servo_pos){
    if(pub_message_ptr_ == nullptr){
        throw std::invalid_argument("pub_message_ptr_ was not initialised");
    }
    else {
        auto message = maestro_interfaces::msg::MaestroTarget();
        message.speed = 0;
        message.acceleration = 0;



        message.channel = servo_ids_[0];
        message.target_ang = new_servo_pos[0];
        pub_message_ptr_->publish(message);

        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

        message.channel = servo_ids_[1];
        message.target_ang = new_servo_pos[1];
        pub_message_ptr_->publish(message);

        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

        message.channel = servo_ids_[2];
        message.target_ang = new_servo_pos[2];
        pub_message_ptr_->publish(message);

        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

        while(last_known_pos[0] != new_servo_pos[0] and last_known_pos[1] != new_servo_pos[1] and last_known_pos[2] != new_servo_pos[2]){}

    }
}
