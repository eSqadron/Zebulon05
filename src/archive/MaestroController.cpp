#include "MaestroController.hpp"
#include <stdexcept>
#include <algorithm>
#include <System>


void Servo::setTarget(int new_target){
    if(new_target < this->max_t && new_target > min_t)
        target = new_target;
    else
        throw std::invalid_argument("Target out of range!");
}


MaestroController::MaestroController(int controller_size){
    int possible_sizes[] = {6, 12, 18, 24};
    if(std::find(std::begin(possible_sizes), std::end(possible_sizes), controller_size) == std::end(possible_sizes))
        throw std::invalid_argument("controller of this size doesn't exist!");

    controller_size_t = controller_size;
    this->servos = new Servo[controller_size];

    System::IO::Ports::SerialPort port;

};


void MaestroController::setTarget(int servo_num, int new_target) {
    if(servo_num >= this->controller_size_t)
        throw std::invalid_argument("Controller size is smaller!");
    this->servos[servo_num].setTarget(new_target);
}


void sendTargets(){
    
}