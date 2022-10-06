//
// Created by OEM on 05.10.2022.
//

#include "../include/RobotLeg/RobotLegRosWrapper.hpp"

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
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}
