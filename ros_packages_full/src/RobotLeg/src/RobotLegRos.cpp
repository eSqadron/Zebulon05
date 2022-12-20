//
// Created by OEM on 07.10.2022.
//

#include "../include/RobotLeg/RobotLegRos.hpp"

#include <cmath>

#define PI 3.14159265359


short unsigned int rad2qns(float rad){
    // 2496 * 4: -90, -PI/2
    // 496 * 4: 90, PI/2
    // 1496 * 4: 0, 0
    float temp = (((rad * 1000)/(PI/2)) + 1500)*4;

    if(temp > 2496*4) temp = 2496*4;
    if(temp <  496*4) temp =  496*4;

    return static_cast<unsigned int>(temp);
}
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
    float x = xyz_pos[0];
    float y = xyz_pos[1];
    float z = xyz_pos[2];
    result_rad[0] = atan(y/x);
    result_rad[2] = acos((pow(x-a_1_, 2) + pow(z +  h_1_, 2) - pow(a_2_, 2) - pow(a_3_, 2))/(2*a_2_*a_3_));

    float r_1_p1 = atan((h_1_ + z) / (x - a_1_));
    float r_1_p2 = atan(a_3_ * sin(result_rad[2]) / (a_2_ + a_3_ * cos(result_rad[2])));

    float r_2_gr = acos(-static_cast<float>(a_2_)/static_cast<float>(a_3_));

    if(result_rad[2] < r_2_gr){
        // r_1_p2 - stays unchanged
    }
    else if(result_rad[2] == r_2_gr){
        r_1_p2 = PI/2;
    }
    else if(result_rad[2] > r_2_gr){
        r_1_p2 = PI + r_1_p2;
    }

    result_rad[1] = r_1_p1 + r_1_p2;
    return result_rad;
}

void RobotLegRos::move_leg_xyz(float x, float y, float z){
    std::array<float, 3> inv_k = inverse_kinematics({x, y, z});
//    temp_out_buffer_ = inv_k[1];
//    temp_out_buffer2_ = rad2qns(temp_out_buffer_);

    inv_k[1] = inv_k[1] - (35 * PI/180);
    inv_k[2] = inv_k[2] - (70 * PI/180);

    publish_servo_position({rad2qns(inv_k[0]), rad2qns(inv_k[1]), rad2qns(inv_k[2])});
}

void RobotLegRos::publish_servo_position(std::array<short unsigned int, 3> new_servo_pos){
    if(pub_message_ptr_ == nullptr){
        throw std::invalid_argument("pub_message_ptr_ was not initialised");
    }
    else {
        target_pos_ = new_servo_pos;

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
        rclcpp::sleep_for(std::chrono::milliseconds(5));

        message2.channel = servo_ids_[1];
        message2.target_ang = new_servo_pos[1];
        pub_message_ptr_->publish(message2);
        rclcpp::sleep_for(std::chrono::milliseconds(5));

        message3.channel = servo_ids_[2];
        message3.target_ang = new_servo_pos[2];
        pub_message_ptr_->publish(message3);
        rclcpp::sleep_for(std::chrono::milliseconds(5));

    }
}
