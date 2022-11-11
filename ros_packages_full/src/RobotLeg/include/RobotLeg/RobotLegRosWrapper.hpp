//
// Created by OEM on 07.10.2022.
//

#ifndef ROBOTLEG_ROBOTLEGROSWRAPPER_HPP
#define ROBOTLEG_ROBOTLEGROSWRAPPER_HPP



#include <chrono>
#include <functional>
#include <memory>
//#include <string>
#include <sstream>

#include "rclcpp/rclcpp.hpp"
#include "maestro_interfaces/msg/maestro_target.hpp"
#include "maestro_interfaces/msg/current_positions.hpp"

#include "geometry_msgs/msg/point.hpp"
#include "std_msgs/msg/bool.hpp"


//#include "walking_robot_interfaces/msg/step.hpp"

#include "RobotLegRos.hpp"

using namespace std::chrono_literals;

class RobotLegRosWrapper : public rclcpp::Node{
public:
    RobotLegRosWrapper() : Node("robot_leg_ros_wrapper"), count_(0){
        publisher_ = this->create_publisher<maestro_interfaces::msg::MaestroTarget>("maestro_target", 10);

        this->declare_parameter("leg_no", 1);
       // this->declare_parameter("servo_ids", {0, 1, 2});
        this->declare_parameter("servo_ids");
    this->set_parameters({rclcpp::Parameter("servo_ids", std::array<short unsigned int, 3>({0, 1, 2}))});

        std::ostringstream temp_stream;
        temp_stream << "step_done_" << this->get_parameter("leg_no").get_parameter_value().get<int>();
        //RCLCPP_INFO(this->get_logger(), temp_stream.str().c_str());
        step_done_feedback_ = this->create_publisher<std_msgs::msg::Bool>(temp_stream.str(), 10); // true when leg is idle
        temp_stream.str("");
        temp_stream.clear();

        robo_leg.set_publisher(publisher_);
        robo_leg.set_physical_params(40, 55, 125, 180);

        subscription_ = this->create_subscription<maestro_interfaces::msg::CurrentPositions>("current_positions", 10, std::bind(&RobotLegRosWrapper::cur_pos_callback, this, std::placeholders::_1));

        temp_stream << "xyz_endpoint_" << this->get_parameter("leg_no").get_parameter_value().get<int>();
        step_subscription_ = this->create_subscription<geometry_msgs::msg::Point>(temp_stream.str(), 10, std::bind(&RobotLegRosWrapper::step_callback, this, std::placeholders::_1));
        temp_stream.flush();

        robo_leg.set_servo_ids(this->get_parameter("servo_ids").get_parameter_value().get<std::array<short unsigned int, 3>>());

    }

private:
    void cur_pos_callback(const maestro_interfaces::msg::CurrentPositions & msg);
    void step_callback(const geometry_msgs::msg::Point& msg);

    //rclcpp::TimerBase::SharedPtr timer_;

    rclcpp::Publisher<maestro_interfaces::msg::MaestroTarget>::SharedPtr publisher_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr step_done_feedback_;

    rclcpp::Subscription<maestro_interfaces::msg::CurrentPositions>::SharedPtr subscription_;
    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr step_subscription_;

    size_t count_;
    RobotLegRos robo_leg;
};





#endif //ROBOTLEG_ROBOTLEGROSWRAPPER_HPP
