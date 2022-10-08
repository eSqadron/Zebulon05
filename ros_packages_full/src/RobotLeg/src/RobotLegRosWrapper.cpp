//
// Created by OEM on 05.10.2022.
//

#include "../include/RobotLeg/RobotLegRosWrapper.hpp"

void RobotLegRosWrapper::timer_callback(){
    try{
        robo_leg.do_step(1, 1);
    } catch(const std::invalid_argument& e){
        RCLCPP_INFO(this->get_logger(), e.what());
    }

}

void RobotLegRosWrapper::cur_pos_callback(const maestro_interfaces::msg::CurrentPositions& msg){
    robo_leg.write_last_known_positions(msg.current_ang);
}

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotLegRosWrapper>());
    rclcpp::shutdown();
    return 0;
}
