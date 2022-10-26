//
// Created by OEM on 07.10.2022.
//

#include "../include/RobotLeg/RobotLegRos.hpp"

#include <cmath>

#define PI 3.14159265359

//void RobotLegRos::do_step(int step_length, int step_height){
//        this->publish_position(std::array<unsigned int, 3>({2496 * 4, 2496 * 4, 2496 * 4 * step_length * step_height}));
//
//        this->publish_position(std::array<unsigned int, 3>({496  * 4, 496  * 4, 496  * 4 * step_length * step_height}));
//
//}

//std::vector<std::array<unsigned int, 3>> RobotLegRos::interpolate_step(short unsigned int step_type, short int step_ang, int step_length, int step_height){
//    // step ang i step_length jest bez sensu, powinno być jedno i z góry narzucony rozstaw nóg
//    // chyba że ma się poruszać w stronę nogi a nie zawsze w stronę pomiędzy nogami
//    std::vector<std::array<unsigned int, 3>> result;
//    // 2496 * 4: -90
//    // 496 * 4: 90
//
//    if(step_type == 0) {
//        result.push_back({1486 * 4, 1913 * 4, 2400 * 4}); // inverse_kinematics(0, 100, 0) angle, leg_length, leg_height
//        // leg_length = step_ang/sin(step_type)
//        // leg_height =  step_height
//
//        result.push_back({981 * 4, 2195 * 4, 2107 * 4}); // inverse_kinematics(45, 100, 100)
//        //result.push_back({981 * 4, 1913 * 4, 2400 * 4}); // inverse_kinematics(45, 100, 0)
//        //result.push_back({1991 * 4, 1913 * 4, 2400 * 4}); // inverse_kinematics(-45, 100, 0)
//        //result.push_back({1486 * 4, 2195 * 4, 2107 * 4}); // inverse_kinematics(0, 100, 100)
//
//        result.push_back({1486 * 4, 1913 * 4, 2400 * 4}); // inverse_kinematics(0, 100, 0)
//    }
//
//    return result;
//}
//
//
//void RobotLegRos::start_performing_step(short unsigned int step_type, short int step_ang, int step_length, int step_height){
//    if(step_stage_==idle){
//        step_stage_ = start_step;
//        interpolated_step_stages_ = interpolate_step(step_type, step_ang, step_length, step_height);
//    }
//    else{
//        throw std::invalid_argument("received negative value");
//    }
//
//}
//
//void RobotLegRos::perform_step(){
//    if(step_stage_ == idle){
//        step_stage_ = idle;
//    }
//    else if(step_stage_ == start_step){
//        interpolated_stage_num_ = 0;
//        publish_position(interpolated_step_stages_[interpolated_stage_num_]);
//        step_stage_ = performing_step;
//    }
//    else if(step_stage_ == performing_step){
//        if((last_known_pos[0] == interpolated_step_stages_[interpolated_stage_num_][0]) and
//           (last_known_pos[1] == interpolated_step_stages_[interpolated_stage_num_][1]) and
//           (last_known_pos[2] == interpolated_step_stages_[interpolated_stage_num_][2])){
//            step_stage_ = increment_step;
//        }
//        else{
//            //publish_position(interpolated_step_stages_[interpolated_stage_num_]);
//            step_stage_ = performing_step;
//        }
//    }
//    else if(step_stage_ == increment_step){
//        interpolated_stage_num_++;
//        if(interpolated_stage_num_ == interpolated_step_stages_.size()){
//            step_stage_ = finish_step;
//        }
//        else{
//            publish_position(interpolated_step_stages_[interpolated_stage_num_]);
//            step_stage_ = performing_step;
//        }
//    }
//    else if(step_stage_ == finish_step){
//        interpolated_step_stages_ = std::vector<std::array<unsigned int, 3>>();
//        interpolated_stage_num_ = 0;
//
//        step_stage_ = idle;
//    }
//}

//float deg2rad(int deg_ang){
//    return (deg_ang * (PI / 180));
//}
//
//int rad2deg(float rad_ang){
//    return (rad_ang * (180 / PI));
//}

//float quarter_nano_seconds_to_rad(int angle){
//    return angle; //TODO
//}

unsigned int rad2qns(float rad){
    // 2496 * 4: -90, -PI/2
    // 496 * 4: 90, PI/2
    // 1496 * 4: 0, 0

    return static_cast<unsigned int>((((rad * 1000)/(PI/2)) + 1496)*4);
}

//bool RobotLegRos::is_step_being_performed(){
//    //if(step_stage_ != idle) return true;
//    return false;
//}

std::array<float, 3> RobotLegRos::forward_kinematics(const std::array<float, 3> angles_deg){
    //std::array<float, 3> angles_deg = {quarter_nano_seconds_to_rad(angles[0]), quarter_nano_seconds_to_rad(angles[1]), quarter_nano_seconds_to_rad(angles[2])};
    std::array<float, 3> result;
    float a_temp = a_2_ * cos(angles_deg[1]) + a_3_ * cos(angles_deg[2] - angles_deg[1]) + a_1_;
    result[0] = a_temp * cos(angles_deg[0]);
    result[1] = a_temp * sin(angles_deg[0]);
    result[2] = a_2_ * sin(angles_deg[1]) - a_3_ * sin(angles_deg[2] - angles_deg[1]);

    return result;
}

std::array<float, 3> RobotLegRos::inverse_kinematics(const std::array<float, 3> xyz_pos){
    std::array<float, 3> result_rad;
    int x = xyz_pos[0];
    int y = xyz_pos[1];
    int z = xyz_pos[2];
    result_rad[0] = atan(y/x);
    result_rad[2] = PI - acos((pow(x-a_1_, 2) + pow(z - h_1_, 2) - pow(a_2_, 2) - pow(a_3_, 2))/(2*a_2_*a_3_));
    result_rad[1] = atan((z - h_1_)/(x - a_1_)) - asin(a_3_ * sin(result_rad[2])/(sqrt(pow(x - a_1_, 2) + pow(z - h_1_, 2))));
    temp_out_buffer_ = result_rad[0];
    return result_rad;
}

void RobotLegRos::move_leg_xyz(float x, float y, float z){
    std::array<float, 3> inv_k = inverse_kinematics({x, y, z});
    publish_servo_position({rad2qns(inv_k[0]), rad2qns(inv_k[1]), rad2qns(inv_k[2])});
}

void RobotLegRos::publish_servo_position(std::array<unsigned int, 3> new_servo_pos){
    if(pub_message_ptr_ == nullptr){
        throw std::invalid_argument("pub_message_ptr_ was not initialised");
    }
    else {
        auto message1 = maestro_interfaces::msg::MaestroTarget();
        auto message2 = maestro_interfaces::msg::MaestroTarget();
        auto message3 = maestro_interfaces::msg::MaestroTarget();
        int max_spd = 100; //160 max?
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
