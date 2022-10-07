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
    RobotLegRos(rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr) : pub_message_ptr_(pub_message_ptr);
    void do_step(int step_length, int step_height);
    int target_i = 4*496;
    int sweep_dir = 1;

private:
    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr pub_message_ptr_;

};


#endif //ROBOTLEG_ROBOTLEGROS_HPP
