//
// Created by OEM on 05.10.2022.
//

#include "../include/RobotLeg/RobotLegRosWrapper.hpp"

#include <string>

void RobotLegRosWrapper::cur_pos_callback(const maestro_interfaces::msg::CurrentPositions& msg){
    robo_leg.save_last_known_servo_positions(msg.current_ang);

    auto feedback_msg = std_msgs::msg::Bool();

    if(robo_leg.get_servo_movement_target() == std::array<short unsigned int, 3>{msg.current_ang[get_servo_ids[0]], msg.current_ang[get_servo_ids[1]], msg.current_ang[get_servo_ids[2]]}){
        feedback_msg.data = true;
    } else{
        feedback_msg.data = false;
    }

    step_done_feedback_->publish(feedback_msg);
}

void RobotLegRosWrapper::step_callback(const geometry_msgs::msg::Point& msg){
    robo_leg.move_leg_xyz(msg.x, msg.y, msg.z);
//    RCLCPP_INFO(this->get_logger(), std::to_string(robo_leg.temp_out_buffer_).c_str());
//    RCLCPP_INFO(this->get_logger(), std::to_string(robo_leg.temp_out_buffer2_).c_str());
//    RCLCPP_INFO(this->get_logger(), " ");

}

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotLegRosWrapper>());
    rclcpp::shutdown();
    return 0;
}
