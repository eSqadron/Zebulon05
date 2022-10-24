//
// Created by OEM on 07.10.2022.
//

#ifndef ROBOTLEG_ROBOTLEGROSWRAPPER_HPP
#define ROBOTLEG_ROBOTLEGROSWRAPPER_HPP



#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "maestro_interfaces/msg/maestro_target.hpp"
#include "maestro_interfaces/msg/current_positions.hpp"

#include "geometry_msgs/msg/point.hpp"


//#include "walking_robot_interfaces/msg/step.hpp"

#include "RobotLegRos.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class RobotLegRosWrapper : public rclcpp::Node{
public:
    RobotLegRosWrapper() : Node("robot_leg_ros_wrapper"), count_(0){
        publisher_ = this->create_publisher<maestro_interfaces::msg::MaestroTarget>("maestro_target", 10);
        timer_ = this->create_wall_timer(100ms, std::bind(&RobotLegRosWrapper::timer_callback, this));
        robo_leg.set_publisher(publisher_);
        robo_leg.set_physical_params(40, 55, 125, 180);

        subscription_ = this->create_subscription<maestro_interfaces::msg::CurrentPositions>("current_positions", 10, std::bind(&RobotLegRosWrapper::cur_pos_callback, this, std::placeholders::_1));
        step_subscription_ = this->create_subscription<geometry_msgs::msg::Point>("xyz_endpoint_1", 10, std::bind(&RobotLegRosWrapper::step_callback, this, std::placeholders::_1));
    }

private:
    void cur_pos_callback(const maestro_interfaces::msg::CurrentPositions & msg);
    void timer_callback();
    void step_callback(const geometry_msgs::msg::Point& msg);

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr publisher_;
    rclcpp::Subscription<maestro_interfaces::msg::CurrentPositions>::SharedPtr subscription_;
    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr step_subscription_;

    size_t count_;
    RobotLegRos robo_leg;
};





#endif //ROBOTLEG_ROBOTLEGROSWRAPPER_HPP
