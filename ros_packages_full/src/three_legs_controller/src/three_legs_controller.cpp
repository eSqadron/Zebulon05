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



#include "../include/three_legs_controller/three_legs_controller.hpp"



ThreeLegsController::ThreeLegsController() : Node("three_legs_controller"){
    step_publishers_[0] = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_1", 10);
    step_publishers_[1] = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_2", 10);
    step_publishers_[2] = this->create_publisher<geometry_msgs::msg::Point>("xyz_endpoint_3", 10);

    timer_ = this->create_wall_timer(30ms, std::bind(&ThreeLegsController::timer_callback, this));

    step1_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_1", 10, std::bind(&ThreeLegsController::step1_done_callback, this, std::placeholders::_1));
    step2_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_2", 10, std::bind(&ThreeLegsController::step2_done_callback, this, std::placeholders::_1));
    step3_done_feedback_sub_ = this->create_subscription<std_msgs::msg::Bool>("step_done_3", 10, std::bind(&ThreeLegsController::step3_done_callback, this, std::placeholders::_1));

    int leg_1_pos = 30;
    int leg_2_pos = 300;
    int leg_3_pos = 180;



    gen_.set_leg_default_positions(PI * 60/180, PI, PI * 300/180);
    gen_.set_step_len(50);
    gen_.set_step_height_point(45);

    auto message = geometry_msgs::msg::Point();
    // message.x = 55 + 125 + 180;
    // message.y = 0;
    // message.z = -40;
    rclcpp::sleep_for(std::chrono::seconds(2));
    // step_publishers_[0]->publish(message);
    // RCLCPP_INFO(this->get_logger(), "leg_1_straightened");
    // rclcpp::sleep_for(std::chrono::seconds(2));
    // step_publishers_[1]->publish(message);
    // RCLCPP_INFO(this->get_logger(), "leg_2_straightened");
    // rclcpp::sleep_for(std::chrono::seconds(2));
    // step_publishers_[2]->publish(message);
    // RCLCPP_INFO(this->get_logger(), "leg_3_straightened");
    // rclcpp::sleep_for(std::chrono::seconds(2));

    leg_no_step_done_ = std::array<bool, 3>{true, true, true};

    xy_leg_positions_ = std::array<std::array<float, 3>, 3>{std::array<float, 3>{150, 0, -100}, std::array<float, 3>{150, 0, -100}, std::array<float, 3>{150, 0, -100}};
    current_single_step_stage_ = initialise_step;

    for(int i =0; i<3; ++i){
        message.x = xy_leg_positions_[i][0];
        message.y = xy_leg_positions_[i][1];
        message.z = xy_leg_positions_[i][2];
        step_publishers_[i]->publish(message);
        rclcpp::sleep_for(std::chrono::seconds(2));
        RCLCPP_INFO(this->get_logger(), "standing");
    }
    rclcpp::sleep_for(std::chrono::seconds(2));

}


void ThreeLegsController::timer_callback()
{
    auto message = geometry_msgs::msg::Point();

    static float endpoint_x_shift = 0;
    static float endpoint_y_shift = 0;
    static short unsigned int moving_leg = 0;
    static float local_step_height = 0;
    static bool local_wait_for_all = false;

    bool all_steps_done = (leg_no_step_done_[0] and leg_no_step_done_[1] and leg_no_step_done_[2]);
    bool this_step_done =  leg_no_step_done_[moving_leg];

    bool action_condition = (local_wait_for_all) ? all_steps_done : this_step_done;

    if(current_single_step_stage_ == initialise_step) {
        try{
            step_result do_step_result = gen_.do_step(0);
            if(DEBUG_MODE)
                RCLCPP_INFO(this->get_logger(), "init step!");
            endpoint_x_shift = do_step_result.delta_x;
            endpoint_y_shift = do_step_result.delta_y;
            moving_leg = do_step_result.leg_making_move;
            local_step_height = do_step_result.peak_z_height;
            local_wait_for_all = do_step_result.wait_for_all;
            action_condition = (local_wait_for_all) ? all_steps_done : this_step_done;
            

            current_single_step_stage_ = leg_up;
        } catch(std::invalid_argument e){
            RCLCPP_INFO(this->get_logger(), e.what());
        }
    } else if(current_single_step_stage_ == leg_up) {
        if(DEBUG_MODE){
            RCLCPP_INFO(this->get_logger(), "leg up");
            RCLCPP_INFO(this->get_logger(), std::to_string(moving_leg).c_str());
            RCLCPP_INFO(this->get_logger(), std::to_string(action_condition).c_str());
            RCLCPP_INFO(this->get_logger(), (std::to_string(leg_no_step_done_[0]) + std::to_string(leg_no_step_done_[1]) + std::to_string(leg_no_step_done_[2])).c_str());
        }
        if(action_condition) {
            if(DEBUG_MODE){
                RCLCPP_INFO(this->get_logger(), "step done, moving!");
            }
            xy_leg_positions_[moving_leg][0] += endpoint_x_shift / 2;
            xy_leg_positions_[moving_leg][1] += endpoint_y_shift / 2;
            xy_leg_positions_[moving_leg][2] += local_step_height;
            message.x = xy_leg_positions_[moving_leg][0];
            message.y = xy_leg_positions_[moving_leg][1];
            message.z = xy_leg_positions_[moving_leg][2];
            step_publishers_[moving_leg]->publish(message);

            current_single_step_stage_ = leg_down;
        }
    } else if(current_single_step_stage_ == leg_down){
        if(DEBUG_MODE){
            RCLCPP_INFO(this->get_logger(), "leg down");
            RCLCPP_INFO(this->get_logger(), std::to_string(moving_leg).c_str());
        }
        if(action_condition) {
            if(DEBUG_MODE){
                RCLCPP_INFO(this->get_logger(), "step done, moving!");
            }
            xy_leg_positions_[moving_leg][0] += endpoint_x_shift / 2;
            xy_leg_positions_[moving_leg][1] += endpoint_y_shift / 2;
            xy_leg_positions_[moving_leg][2] -= local_step_height;
            message.x = xy_leg_positions_[moving_leg][0];
            message.y = xy_leg_positions_[moving_leg][1];
            message.z = xy_leg_positions_[moving_leg][2];
            step_publishers_[moving_leg]->publish(message);

            current_single_step_stage_ = initialise_step;
        }
    }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ThreeLegsController>());
  rclcpp::shutdown();
  return 0;
}
