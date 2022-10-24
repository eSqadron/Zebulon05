// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class ThreeLegsController : public rclcpp::Node
{
public:
    ThreeLegsController()
    : Node("three_legs_controller"), count_(0)
    {
        step_1_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_1", 10);
        step_2_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_2", 10);
        step_3_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_3", 10);
        timer_ = this->create_wall_timer(5000ms, std::bind(&ThreeLegsController::timer_callback, this));
        counter = 0;

    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Point();
        if(counter == 0) {
            message.x = 100;
            message.y = 100;
            message.z = 100;
        } else if (counter == 1){
            message.x = 100;
            message.y = 100;
            message.z = 0;
        } else if (counter == 2){
            message.x = 0;
            message.y = 0;
            message.z = 0;
        }


        step_1_publisher_->publish(message);
        counter++;
        if(counter >= 3) counter = 0;
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr step_1_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr step_2_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr step_3_publisher_;
    //size_t count_;
    int counter;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ThreeLegsController>());
  rclcpp::shutdown();
  return 0;
}
