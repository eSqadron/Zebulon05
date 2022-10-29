//
// Created by OEM on 05.10.2022.
//

#ifndef ZEBULON05_ROBOTLEGROSWRAPPER_HPP
#define ZEBULON05_ROBOTLEGROSWRAPPER_HPP

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "maestro_interfaces/msg/MaestroTarget.hpp"
#include "maestro_interfaces/msg/CurrentPositions.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class RobotLegRosWrapper : public rclcpp::Node{
public:
    RobotLegRosWrapper() : Node("robot_leg_ros_wrapper"), count_(0){
        publisher_ = this->create_publisher<maestro_interfaces::msg::MaestroTarget>("maestro_target", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }
private:

    int target_i = 4*496;
    int sweep_dir = 1;

    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}

#endif //ZEBULON05_ROBOTLEGROSWRAPPER_HPP
