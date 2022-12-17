//
// Created by OEM on 14.10.2022.
//

#ifndef THREE_LEGS_CONTROLLER_THREE_LEGS_CONTROLLER_HPP
#define THREE_LEGS_CONTROLLER_THREE_LEGS_CONTROLLER_HPP

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "std_msgs/msg/bool.hpp"
#include "Generator3A.hpp"

#define PI 3.14159265359

using namespace std::chrono_literals;


enum single_step_stages{
    initialise_step,
    leg_up,
    leg_down
};



class ThreeLegsController : public rclcpp::Node
{
public:
    ThreeLegsController() : Node("three_legs_controller");

private:
    void timer_callback();


    void step1_done_callback(const std_msgs::msg::Bool& msg){
        leg_no_step_done_[0] = msg.data;
    }
    void step2_done_callback(const std_msgs::msg::Bool& msg){
        leg_no_step_done_[1] = msg.data;
    }
    void step3_done_callback(const std_msgs::msg::Bool& msg){
        leg_no_step_done_[2] = msg.data;
    }

    std::array<std::array<float, 3>, 3> xy_leg_positions_;

    std::array<bool, 3> leg_no_step_done_;

    single_step_stages current_single_step_stage_;
    float step_height_;

    Generator3A gen_;

    rclcpp::TimerBase::SharedPtr timer_;

    std::array<rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr, 3> step_publishers_;


    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr step1_done_feedback_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr step2_done_feedback_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr step3_done_feedback_sub_;

    float endpoint_x_shift;
    float endpoint_y_shift;
    unsigned short int moving_leg;
};

#endif //THREE_LEGS_CONTROLLER_THREE_LEGS_CONTROLLER_HPP
