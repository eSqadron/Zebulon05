//
// Created by OEM on 14.11.2022.
//

#ifndef THREE_LEGS_CONTROLLER_GENERATOR3A_HPP
#define THREE_LEGS_CONTROLLER_GENERATOR3A_HPP

#include <array>
#include <tuple>
#include <cmath>
#include <stdexcept>


enum step_stage{
    NA,
    Idle,
    R_for,
    L_for,
    M_for,
    R_back,
    L_back,
    M_back,
    Change_dir
};


struct step_result{
    float delta_x;
    float delta_y;
    float delta_z = 0;
    short unsigned int leg_making_move;
    float peak_z_height;
};


class StepGenerator{
public:
    StepGenerator(){
        restart_generator();
    }

    virtual step_result do_step(float ang) = 0;

    void set_leg_default_positions(float pos1, float pos2, float pos3){
        leg_pos_ = {pos1, pos2, pos3};
    }

    void set_step_len(int new_len){
        step_len_ = new_len;
    }

    void restart_generator(){
        current_step_stage_ = Idle;
        current_right_leg_ = 0;
        current_left_leg_ = 0;
        current_back_leg_ = 0;
    }

        void set_step_height_point(float new_height_point){
        step_height_point_ = new_height_point;
    }

protected:

    std::array<float, 2> calculate_endpoint_delta(float ang, unsigned short int leg_no, bool inverse = false){
        float delta_x = step_len_ * cos(ang - leg_pos_[leg_no]);
        float delta_y = step_len_ * sin(ang - leg_pos_[leg_no]);
        if(inverse){
            delta_x = -delta_x;
            delta_y = -delta_y;
        }
        return std::array<float, 2>{delta_x, delta_y};
    }

    void calculate_right_leg(float ang){
        unsigned short int leg_no = 0;
        for (unsigned short int i = 1; i < 3; ++i) {
            if(leg_pos_[i] - ang < leg_pos_[leg_no] - ang){
                leg_no = i;
            }
        }
        current_right_leg_ = leg_no;
        current_back_leg_ = (leg_no+1)%3;
        current_left_leg_ = (leg_no+2)%3;


    }


    step_stage current_step_stage_;
    unsigned short int current_right_leg_;
    unsigned short int current_left_leg_;
    unsigned short int current_back_leg_;

    std::array<float, 3> leg_pos_;
    int step_len_;
    float step_height_point_;
};


class Generator3A: public StepGenerator{
public:
    step_result do_step(float ang) override {
        calculate_right_leg(ang);
        step_result res;
        res.delta_z = 0;
        res.peak_z_height = step_height_point_;

        if(current_step_stage_ ==  Idle) {
            res.delta_x = 0;
            res.delta_y = 0;
            res.leg_making_move = 0;
            current_step_stage_ = R_for;
        }
        
        if(current_step_stage_ == R_for){
            std::array<float, 2> endpoint = calculate_endpoint_delta(ang, current_right_leg_);
            res.delta_x = endpoint[0];
            res.delta_y = -endpoint[1];
            res.leg_making_move = current_right_leg_;
            current_step_stage_ = L_for;
        } else if(current_step_stage_ == L_for){
            std::array<float, 2> endpoint = calculate_endpoint_delta(ang, current_left_leg_);
            res.delta_x = endpoint[0];
            res.delta_y = -endpoint[1];
            res.leg_making_move = current_left_leg_;
            current_step_stage_ = M_for;
        } else if(current_step_stage_ == M_for){
            std::array<float, 2> endpoint = calculate_endpoint_delta(ang, current_back_leg_);
            res.delta_x = 2.0/3.0 * endpoint[0];
            res.delta_y = -2.0/3.0 * endpoint[1];
            res.leg_making_move = current_back_leg_;
            current_step_stage_ = R_back;
        } else if(current_step_stage_ == R_back){
            std::array<float, 2> endpoint = calculate_endpoint_delta(ang, current_right_leg_);
            res.delta_x = -endpoint[0];
            res.delta_y = endpoint[1];
            res.leg_making_move = current_right_leg_;
            res.peak_z_height = 0;
            current_step_stage_ = L_back;
        } else if(current_step_stage_ == L_back){
            std::array<float, 2> endpoint = calculate_endpoint_delta(ang, current_left_leg_);
            res.delta_x = -endpoint[0];
            res.delta_y = endpoint[1];
            res.leg_making_move = current_left_leg_;
            res.peak_z_height = 0;
            current_step_stage_ = M_back;
        } else if(current_step_stage_ == M_back){
            std::array<float, 2> endpoint = calculate_endpoint_delta(ang, current_back_leg_);
            res.delta_x = -2.0/3.0 * endpoint[0];
            res.delta_y = 2.0/3.0 * endpoint[1];
            res.leg_making_move = current_back_leg_;
            res.peak_z_height = 0;
            current_step_stage_ = Idle;
        } else{
            throw std::invalid_argument("unknown stage");
        }

        return res;
    }
};


#endif //THREE_LEGS_CONTROLLER_GENERATOR3A_HPP
