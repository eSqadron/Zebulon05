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
    RobotLegRos(rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr) : pub_message_ptr_(pub_message_ptr) : last_known_pos{0} {};
    RobotLegRos() : RobotLegRos(nullptr) {};
    void set_publisher(rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr){
        pub_message_ptr_ = pub_message_ptr;
    }
    void write_last_known_positions(std::array<short unsigned int, 24> new_last_known_pos){
        last_known_pos = new_last_known_pos;
    }

    void do_step(int step_length, int step_height);
    int target_i = 4*496;
    int sweep_dir = 1;

private:
    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr_;
    std::array<short unsigned int, 24> last_known_pos;

};


#endif //ROBOTLEG_ROBOTLEGROS_HPP
