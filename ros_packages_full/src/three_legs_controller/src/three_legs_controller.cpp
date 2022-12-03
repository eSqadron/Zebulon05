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

enum step_stage_old{
    NA_,
    Idle_,
    Right_forward,
    Middle_back,
    Change_dir_
};

enum single_step_stages{
    initialise_step,
    leg_up,
    leg_down
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
        step2_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_2", 10, std::bind(&ThreeLegsController::step2_done_callback, this, std::placeholders::_1));
        step3_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_3", 10, std::bind(&ThreeLegsController::step3_done_callback, this, std::placeholders::_1));

        current_step_stage_ = Idle_;

//        int leg_1_pos = get_pos_from_leg("leg_1");
//        int leg_2_pos = get_pos_from_leg("leg_2");
//        int leg_3_pos = get_pos_from_leg("leg_3");
        int leg_1_pos = 30;
        int leg_2_pos = 300;
        int leg_3_pos = 180;


        gen_.set_leg_default_positions(PI * 60/180, PI, PI * 300/180);

        auto message = geometry_msgs::msg::Point();
        message.x = 55 + 125 + 180;
        message.y = 0;
        message.z = -40;
        step_1_publisher_->publish(message);
        rclcpp::sleep_for(std::chrono::seconds(1));
        step_2_publisher_->publish(message);
        rclcpp::sleep_for(std::chrono::seconds(1));
        step_3_publisher_->publish(message);
        rclcpp::sleep_for(std::chrono::seconds(1));
        is_step1_stage_done_ = true;
        is_step2_stage_done_ = true;
        is_step3_stage_done_ = true;
        leg_no_step_done_ = std::array<bool, 3>{true, true, true};

        xy_leg_positions_ = std::array<std::array<float, 3>, 3>{std::array<float, 3>{150, 0, -100}, std::array<float, 3>{150, 0, -100}, std::array<float, 3>{150, 0, -100}};
        current_single_step_stage_ = initialise_step;
        step_height_ = 40;
    }

private:
    void timer_callback()
    {
        auto message = geometry_msgs::msg::Point();
        //robo_leg.set_physical_params(40, 55, 125, 180);

        std::tuple<std::array<float, 2>, int> do_step_result;
        std::array<float, 2> endpoint_shift;
        int moving_leg;
        
        
        //RCLCPP_INFO(this->get_logger(), std::to_string(is_step1_stage_done_).c_str());

        if(current_step_stage_ == Idle_){
            if(is_step3_stage_done_){
                message.x = 55 + 125 + 100;
                message.y = 0;
                message.z = -40;
                step_3_publisher_->publish(message);
                RCLCPP_INFO(this->get_logger(), "message 3 sent");
                current_step_stage_ = Right_forward;
            }
        }
//        else if(current_step_stage_ == Right_forward) {
//            if (is_step1_stage_done_){
//                message.x = 55 + 125 + 180;
//                message.y = 0;
//                message.z = -40;
//                step_1_publisher_->publish(message);
//                RCLCPP_INFO(this->get_logger(), "message 1 sent");
//                current_step_stage_ = Middle_back;
//            }
//        }
//        else if(current_step_stage_ == Middle_back) {
//            if (is_step1_stage_done_){
//                message.x = 55 + 180;
//                message.y = 0;
//                message.z = -40;
//                step_1_publisher_->publish(message);
//                RCLCPP_INFO(this->get_logger(), "message 1 sent");
//                current_step_stage_ = Right_forward;
//            }
//        }



//        if(current_single_step_stage_ == initialise_step) {
//            do_step_result = gen_.do_step(0);
//            endpoint_shift = std::get<0>(do_step_result);
//            moving_leg = std::get<1>(do_step_result);
//            current_single_step_stage_ = leg_up;
//        } else if(current_single_step_stage_ == leg_up) {
//            if(leg_no_step_done_[moving_leg]) {
//                xy_leg_positions_[moving_leg][0] += endpoint_shift[0] / 2;
//                xy_leg_positions_[moving_leg][1] += endpoint_shift[1] / 2;
//                xy_leg_positions_[moving_leg][2] += step_height_;
//                message.x = xy_leg_positions_[moving_leg][0];
//                message.y = xy_leg_positions_[moving_leg][1];
//                message.z = xy_leg_positions_[moving_leg][2];
//                if (moving_leg == 0)
//                    step_1_publisher_->publish(message);
//                else if (moving_leg == 1)
//                    step_2_publisher_->publish(message);
//                else if (moving_leg == 3)
//                    step_3_publisher_->publish(message);
//
//                current_single_step_stage_ = leg_down;
//            }
//        } else if(current_single_step_stage_ == leg_down){
//            if(leg_no_step_done_[moving_leg]) {
//                xy_leg_positions_[moving_leg][0] += endpoint_shift[0] / 2;
//                xy_leg_positions_[moving_leg][1] += endpoint_shift[1] / 2;
//                xy_leg_positions_[moving_leg][2] -= step_height_;
//                message.x = xy_leg_positions_[moving_leg][0];
//                message.y = xy_leg_positions_[moving_leg][1];
//                message.z = xy_leg_positions_[moving_leg][2];
//                if (moving_leg == 0)
//                    step_1_publisher_->publish(message);
//                else if (moving_leg == 1)
//                    step_2_publisher_->publish(message);
//                else if (moving_leg == 3)
//                    step_3_publisher_->publish(message);
//
//                current_single_step_stage_ = initialise_step;
//            }
//        }



    }

//    int get_pos_from_leg(std::string leg_name){
//        auto parameters_client = std::make_shared<rclcpp::SyncParametersClient>(this, leg_name);
//        while (!parameters_client->wait_for_service(1s)) {
//            if (!rclcpp::ok()) {
//                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
//                rclcpp::shutdown();
//            }
//            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
//        }
//        return parameters_client->get_parameters({"leg_pos"})[0].get_parameter_value().get<int>();
//    }


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

    std::array<std::array<float, 3>, 3> xy_leg_positions_;

    bool is_step1_stage_done_;
    bool is_step2_stage_done_;
    bool is_step3_stage_done_;
    std::array<bool, 3> leg_no_step_done_;

    step_stage_old current_step_stage_;
    single_step_stages current_single_step_stage_;
    float step_height_;

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
