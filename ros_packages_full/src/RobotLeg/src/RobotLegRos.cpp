//
// Created by OEM on 07.10.2022.
//

#include "../include/RobotLeg/RobotLegRos.hpp"


//void RobotLegRos::do_step(int step_length, int step_height){
//        this->publish_position(std::array<unsigned int, 3>({2496 * 4, 2496 * 4, 2496 * 4 * step_length * step_height}));
//
//        this->publish_position(std::array<unsigned int, 3>({496  * 4, 496  * 4, 496  * 4 * step_length * step_height}));
//
//}

std::vector<std::array<unsigned int, 3>> RobotLegRos::interpolate_step(){
    std::vector<std::array<unsigned int, 3>> result;
    result.push_back({1486 * 4, 1913 * 4, 2400 * 4});

//    result.push_back({981 * 4, 2195 * 4, 2107 * 4});
//    result.push_back({981 * 4, 1913 * 4, 2400 * 4});
//    result.push_back({1991 * 4, 1913 * 4, 2400 * 4});
//    result.push_back({1486 * 4, 2195 * 4, 2107 * 4});

    result.push_back({1486 * 4, 1913 * 4, 2400 * 4});

    return result;
}

void RobotLegRos::perform_step(){
    if(step_stage_ == idle){
        step_stage_ = start_step;
    }
    else if(step_stage_ == start_step){
        interpolated_step_stages_ = interpolate_step();
        interpolated_stage_num_ = 0;
        publish_position(interpolated_step_stages_[interpolated_stage_num_]);
        step_stage_ = performing_step;
    }
    else if(step_stage_ == performing_step){
        if((last_known_pos[0] == interpolated_step_stages_[interpolated_stage_num_][0]) and
           (last_known_pos[1] == interpolated_step_stages_[interpolated_stage_num_][1]) and
           (last_known_pos[2] == interpolated_step_stages_[interpolated_stage_num_][2])){
            step_stage_ = increment_step;
        }
        else{
            //publish_position(interpolated_step_stages_[interpolated_stage_num_]);
            step_stage_ = performing_step;
        }
    }
    else if(step_stage_ == increment_step){
        interpolated_stage_num_++;
        if(interpolated_stage_num_ == interpolated_step_stages_.size()){
            step_stage_ = finish_step;
        }
        else{
            publish_position(interpolated_step_stages_[interpolated_stage_num_]);
            step_stage_ = performing_step;
        }
    }
    else if(step_stage_ == finish_step){
        interpolated_step_stages_ = std::vector<std::array<unsigned int, 3>>();
        interpolated_stage_num_ = 0;

        step_stage_ = idle;
    }
}

void RobotLegRos::publish_position(std::array<unsigned int, 3> new_servo_pos){
    if(pub_message_ptr_ == nullptr){
        throw std::invalid_argument("pub_message_ptr_ was not initialised");
    }
    else {
        auto message1 = maestro_interfaces::msg::MaestroTarget();
        auto message2 = maestro_interfaces::msg::MaestroTarget();
        auto message3 = maestro_interfaces::msg::MaestroTarget();
        int max_spd = 160;
        message1.speed = max_spd;
        message1.acceleration = 0;
        message2.speed = max_spd;
        message2.acceleration = 0;
        message3.speed = max_spd;
        message3.acceleration = 0;

        message1.channel = servo_ids_[0];
        message1.target_ang = new_servo_pos[0];
        pub_message_ptr_->publish(message1);
        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

        message2.channel = servo_ids_[1];
        message2.target_ang = new_servo_pos[1];
        pub_message_ptr_->publish(message2);
        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));

        message3.channel = servo_ids_[2];
        message3.target_ang = new_servo_pos[2];
        pub_message_ptr_->publish(message3);
        rclcpp::sleep_for(std::chrono::nanoseconds(1000000));


//        while(((last_known_pos[0] != new_servo_pos[0]) or (last_known_pos[1] != new_servo_pos[1])) or (last_known_pos[2] != new_servo_pos[2])){
//            pub_message_ptr_->publish(message1);
//            rclcpp::sleep_for(std::chrono::nanoseconds(1000000));
//
//            pub_message_ptr_->publish(message2);
//            rclcpp::sleep_for(std::chrono::nanoseconds(1000000));
//
//            pub_message_ptr_->publish(message3);
//            rclcpp::sleep_for(std::chrono::nanoseconds(1000000));
//
//        }

    }
}
