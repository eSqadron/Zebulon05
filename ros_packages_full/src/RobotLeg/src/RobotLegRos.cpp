//
// Created by OEM on 07.10.2022.
//

#include "../include/RobotLeg/RobotLegRos.hpp"


void RobotLegRos::do_step(int step_length, int step_height){
        this->get_servos_to_pos(std::array<unsigned int, 3>({2496 * 4, 2496 * 4, 2496 * 4 * step_length * step_height}));
        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));
        this->get_servos_to_pos(std::array<unsigned int, 3>({496  * 4, 496  * 4, 496  * 4 * step_length * step_height}));
        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));
}

void RobotLegRos::get_servos_to_pos(std::array<unsigned int, 3> new_servo_pos){
    if(pub_message_ptr_ == nullptr){
        throw std::invalid_argument("pub_message_ptr_ was not initialised");
    }
    else {
        auto message1 = maestro_interfaces::msg::MaestroTarget();
        auto message2 = maestro_interfaces::msg::MaestroTarget();
        auto message3 = maestro_interfaces::msg::MaestroTarget();
        message1.speed = 0;
        message1.acceleration = 0;
        message2.speed = 0;
        message2.acceleration = 0;
        message3.speed = 0;
        message3.acceleration = 0;

        message1.channel = servo_ids_[0];
        message1.target_ang = new_servo_pos[0];

        message2.channel = servo_ids_[1];
        message2.target_ang = new_servo_pos[1];

        message3.channel = servo_ids_[2];
        message3.target_ang = new_servo_pos[2];


        while(((last_known_pos[0] != new_servo_pos[0]) or (last_known_pos[1] != new_servo_pos[1])) or (last_known_pos[2] != new_servo_pos[2])){
            pub_message_ptr_->publish(message1);
            rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

            pub_message_ptr_->publish(message2);
            rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

            pub_message_ptr_->publish(message3);
            rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

        }

    }
}
