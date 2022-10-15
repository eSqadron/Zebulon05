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
#include "walking_robot_interfaces/msg/step.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class ThreeLegsController : public rclcpp::Node
{
public:
    ThreeLegsController()
    : Node("three_legs_controller"), count_(0)
    {
        step_1_publisher_ = this->create_publisher<walking_robot_interfaces::msg::Step>("step_1", 10);
        step_2_publisher_ = this->create_publisher<walking_robot_interfaces::msg::Step>("step_2", 10);
        step_3_publisher_ = this->create_publisher<walking_robot_interfaces::msg::Step>("step_3", 10);
        timer_ = this->create_wall_timer(5000ms, std::bind(&ThreeLegsController::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = walking_robot_interfaces::msg::Step();
        message.step_dir = 90;
        message.step_length = 100;
        message.step_height = 100;

        step_1_publisher_->publish(message);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<walking_robot_interfaces::msg::Step>::SharedPtr step_1_publisher_;
    rclcpp::Publisher<walking_robot_interfaces::msg::Step>::SharedPtr step_2_publisher_;
    rclcpp::Publisher<walking_robot_interfaces::msg::Step>::SharedPtr step_3_publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ThreeLegsController>());
  rclcpp::shutdown();
  return 0;
}
