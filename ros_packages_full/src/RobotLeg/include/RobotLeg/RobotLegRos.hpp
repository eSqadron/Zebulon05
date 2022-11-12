//
// Created by OEM on 07.10.2022.
//

#ifndef ROBOTLEG_ROBOTLEGROS_HPP
#define ROBOTLEG_ROBOTLEGROS_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "maestro_interfaces/msg/maestro_target.hpp"

#include <vector>

enum StepStage{
    idle,
    start_step,
    performing_step,
    increment_step,
    finish_step
};

class RobotLegRos {
public:
    RobotLegRos(rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr, std::array<short unsigned int, 3> servo_ids) : pub_message_ptr_(pub_message_ptr), last_known_pos{0}, servo_ids_(servo_ids){
        last_known_pos = {0, 0, 0};
    };
    RobotLegRos() : RobotLegRos(nullptr, {0, 1, 2}) {};
    void set_publisher(rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr){
        pub_message_ptr_ = pub_message_ptr;
    }

    void set_servo_ids(std::array<short unsigned int, 3> new_servo_ids){
        servo_ids_ = new_servo_ids;
        RCLCPP_INFO(this->get_logger(), std::string(servo_ids_.begin(), servo_ids_.end()).c_str());
    }
    std::array<short unsigned int, 3> get_servo_ids(){
        return servo_ids_;
    }

    void set_physical_params(int h1, int a1, int a2, int a3){
        h_1_ = h1;
        a_1_ = a1;
        a_2_ = a2;
        a_3_ = a3;
    }

    void move_leg_xyz(float x, float y, float z);

    void publish_servo_position(std::array<short unsigned int, 3> new_servo_pos);

    std::array<float, 3> forward_kinematics(const std::array<float, 3> angles_deg);
    std::array<float, 3> inverse_kinematics(const std::array<float, 3> xyz_pos);

    void save_last_known_servo_positions(std::array<short unsigned int, 24> new_last_known_pos){
        last_known_pos = new_last_known_pos;
    }
    std::array<short unsigned int, 3> get_servo_movement_target(){
        return target_pos_;
    }

    std::array<short unsigned int, 24> get_last_known_servo_pos(){
        return last_known_pos;
    }

private:
    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr_;
    std::array<short unsigned int, 24> last_known_pos;

    std::array<short unsigned int, 3> target_pos_;
    std::array<short unsigned int, 3> servo_ids_;

    int h_1_;
    int a_1_;
    int a_2_;
    int a_3_;

};


#endif //ROBOTLEG_ROBOTLEGROS_HPP
