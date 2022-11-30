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
#include "std_msgs/msg/bool.hpp"
#include "../include/three_legs_controller/Generator3A.hpp"

#define PI 3.14159265359

using namespace std::chrono_literals;

enum step_stage{
    NA,
    Idle,
    Right_forward,
    Middle_back,
    Change_dir
};



class ThreeLegsController : public rclcpp::Node
{
public:
    ThreeLegsController() : Node("three_legs_controller"){
        step_1_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_1", 10);
        step_2_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_2", 10);
        step_3_publisher_ = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_3", 10);

        timer_ = this->create_wall_timer(200ms, std::bind(&ThreeLegsController::timer_callback, this));

        step1_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_1", 10, std::bind(&ThreeLegsController::step1_done_callback, this, std::placeholders::_1));
        step2_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_1", 10, std::bind(&ThreeLegsController::step2_done_callback, this, std::placeholders::_1));
        step3_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_1", 10, std::bind(&ThreeLegsController::step3_done_callback, this, std::placeholders::_1));

        current_step_stage_ = Idle;

        int leg_1_pos = get_pos_from_leg("leg_1");
        int leg_2_pos = get_pos_from_leg("leg_2");
        int leg_3_pos = get_pos_from_leg("leg_3");


        gen_.set_leg_default_positions(PI * 60/180, PI, PI * 300/180);

        auto message = geometry_msgs::msg::Point();
        message.x = 55 + 125 + 180;
        message.y = 0;
        message.z = -40;
        step_1_publisher_->publish(message);
        rclcpp::sleep_for(std::chrono::seconds(1));
        step_2_publisher_->publish(message);
        rclcpp::sleep_for(std::chrono::seconds(6));
        is_step1_stage_done_ = true;
        is_step2_stage_done_ = true;
        is_step3_stage_done_ = true;
        leg_no_step_done_ = {true, true, true};
    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Point();
        //robo_leg.set_physical_params(40, 55, 125, 180);

        std::tuple<std::array<float, 2>, int> do_step_result;
        std::array<float, 2> endpoint_shift;
        int moving_leg;
        
        
        RCLCPP_INFO(this->get_logger(), std::to_string(is_step1_stage_done_ && is_step2_stage_done_).c_str());

        if(current_step_stage_ == Idle){
            if(is_step2_stage_done_){
                message.x = 55 + 125 + 180;
                message.y = 0;
                message.z = -40;
                step_2_publisher_->publish(message);
                RCLCPP_INFO(this->get_logger(), "message 2 sent");
                current_step_stage_ = Right_forward;
            }
        }
        else if(current_step_stage_ == Right_forward) {
            if (is_step1_stage_done_){
                message.x = 55 + 125;
                message.y = 0;
                message.z = -40;
                step_1_publisher_->publish(message);
                RCLCPP_INFO(this->get_logger(), "message 1 sent");
                current_step_stage_ = Idle;
            }
        }

        do_step_result = gen_.do_step(0);
        endpoint_shift = std::get<0>(do_step_result);
        moving_leg = std::get<1>(do_step_result);



    }

    int get_pos_from_leg(std::string leg_name){
        auto parameters_client = std::make_shared<rclcpp::SyncParametersClient>(this, leg_name);
        while (!parameters_client->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                rclcpp::shutdown();
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }
        return parameters_client->get_parameter("leg_pos");
    }


    void step1_done_callback(const std_msgs::msg::Bool& msg){
        is_step1_stage_done_ = msg.data;
        leg_no_step_done_[0] = msg.data;
    }
    void step2_done_callback(const std_msgs::msg::Bool& msg){
        is_step2_stage_done_ = msg.data;
        leg_no_step_done_[1] = msg.data;
    }
    void step3_done_callback(const std_msgs::msg::Bool& msg){
        is_step3_stage_done_ = msg.data;
        leg_no_step_done_[2] = msg.data;
    }

    bool is_step1_stage_done_;
    bool is_step2_stage_done_;
    bool is_step3_stage_done_;
    std::array<bool, 3> leg_no_step_done_;

    step_stage current_step_stage_;

    Generator3A gen_;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr step_1_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr step_2_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr step_3_publisher_;

    //std::array<rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr, 3>

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr step1_done_feedback_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr step2_done_feedback_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr step3_done_feedback_sub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ThreeLegsController>());
  rclcpp::shutdown();
  return 0;
}
