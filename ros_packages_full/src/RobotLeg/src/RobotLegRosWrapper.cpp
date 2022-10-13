//
// Created by OEM on 05.10.2022.
//

#include "../include/RobotLeg/RobotLegRosWrapper.hpp"

void RobotLegRosWrapper::timer_callback(){
    try{
        robo_leg.perform_step();
    } catch(const std::invalid_argument& e){
        RCLCPP_INFO(this->get_logger(), e.what());
    }

}

void RobotLegRosWrapper::cur_pos_callback(const maestro_interfaces::msg::CurrentPositions& msg){
    robo_leg.write_last_known_positions(msg.current_ang);
    RCLCPP_INFO(this->get_logger(), "%d", robo_leg.get_last_known_pos()[1]);
}

void RobotLegRosWrapper::step_callback(const robot_interfaces::msg::Step& msg){
    if(robo_leg.is_step_being_performed()){
        RCLCPP_INFO(this->get_logger(), "previous step not finished! %d", msg.type);
    }
    else{
        robo_leg.start_step();
    }
}

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotLegRosWrapper>());
    rclcpp::shutdown();
    return 0;
}
