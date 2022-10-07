//
// Created by OEM on 05.10.2022.
//

//#include "../include/RobotLeg/RobotLegRosWrapper.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "maestro_interfaces/msg/maestro_target.hpp"
#include "maestro_interfaces/msg/current_positions.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class RobotLegRosWrapper : public rclcpp::Node{
public:
    RobotLegRosWrapper() : Node("robot_leg_ros_wrapper"), count_(0){
        publisher_ = this->create_publisher<maestro_interfaces::msg::MaestroTarget>("maestro_target", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&RobotLegRosWrapper::timer_callback, this));
    }
private:

    int target_i = 4*496;
    int sweep_dir = 1;

    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr publisher_;
    size_t count_;
};



void RobotLegRosWrapper::timer_callback(){
    auto message = maestro_interfaces::msg::MaestroTarget();
    message.channel = 0;
    message.speed = 0;
    message.acceleration = 0;

    message.target_ang = target_i;
    target_i+=(100*sweep_dir);
    if(target_i > 2496 * 4) sweep_dir = -1;
    if(target_i < 496 * 4) sweep_dir = 1;

    //RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
}


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotLegRosWrapper>());
    rclcpp::shutdown();
    return 0;
}
