//
// Created by OEM on 07.10.2022.
//

#ifndef ROBOTLEG_ROBOTLEGROS_HPP
#define ROBOTLEG_ROBOTLEGROS_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "maestro_interfaces/msg/maestro_target.hpp"

class RobotLegRos {
public:
    RobotLegRos(rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr, std::array<short unsigned int, 3> servo_ids) : pub_message_ptr_(pub_message_ptr), last_known_pos{0}, servo_ids_(servo_ids){};
    RobotLegRos() : RobotLegRos(nullptr), servo_ids_({0, 1, 2}) {};
    void set_publisher(rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr){
        pub_message_ptr_ = pub_message_ptr;
    }
    void set_servo_ids(std::array<short unsigned int, 3> new_servo_ids){
        servo_ids_[0] = new_servo_ids[0];
        servo_ids_[1] = new_servo_ids[1];
        servo_ids_[2] = new_servo_ids[2];
    }

    void get_servos_to_pos(std::array<unsigned int, 3> new_servo_pos);

    void write_last_known_positions(std::array<short unsigned int, 24> new_last_known_pos){
        last_known_pos = new_last_known_pos;
    }

    void do_step(int step_length, int step_height);
    int target_i = 4*496;
    int sweep_dir = 1;


private:
    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr_;
    std::array<short unsigned int, 24> last_known_pos;
    std::array<short unsigned int, 3> servo_ids_;

};


#endif //ROBOTLEG_ROBOTLEGROS_HPP
