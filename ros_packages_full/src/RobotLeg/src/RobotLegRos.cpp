//
// Created by OEM on 07.10.2022.
//

#include "../include/RobotLeg/RobotLegRos.hpp"


void RobotLegRos::do_step(int step_length, int step_height){
    auto message = maestro_interfaces::msg::MaestroTarget();
    message.channel = 0;
    message.speed = 0;
    message.acceleration = 0;

    message.target_ang = target_i;
    target_i+=(100*sweep_dir * step_length*step_height);
    if(target_i > 2496 * 4) sweep_dir = -1;
    if(target_i < 496 * 4) sweep_dir = 1;
    pub_message_ptr_->publish(message);
}
