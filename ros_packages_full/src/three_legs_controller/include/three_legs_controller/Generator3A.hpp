//
// Created by OEM on 14.11.2022.
//

#ifndef THREE_LEGS_CONTROLLER_GENERATOR3A_HPP
#define THREE_LEGS_CONTROLLER_GENERATOR3A_HPP


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


class Generator3A {
public:
    Generator3A(){
        restart_generator();
        step_len_ = 10;
    }

    void set_leg_default_positions(float pos1, float pos2, float pos3){
        leg_pos_ = {pos1, pos2, pos3};
    }

    void restart_generator(){
        current_step_stage_ = Idle;
        current_right_leg_ = 0;
    }

    std::tuple<std::array<float, 2>, int> do_step(int ang){
        if(current_step_stage_ == R_for) {
            current_step_stage_ = R_for;
        }else if(current_step_stage_ == R_for){
            calculate_right_leg(ang);
            return std::make_tuple(calculate_endpoint_delta(ang, current_right_leg_), current_right_leg_);
            current_step_stage_ = L_for;
        }
        else if(current_step_stage_ == L_for){
            calculate_right_leg(ang);
            return std::make_tuple(calculate_endpoint_delta(ang, current_left_leg_), current_left_leg_);
            current_step_stage_ = R_for;
        }
    }

    std::array<float, 2> calculate_endpoint_delta(float ang, int leg_no){
        float delta_x = l * sin(ang - leg_pos_[leg_no]);
        float delta_y = l * cos(ang - leg_pos_[leg_no]);
        return std::array<float, 2>{delta_x, delta_y};
    }

    void calculate_right_leg(int ang){
        int leg_no = 0;
        for (int i = 1; i < 3; ++i) {
            if(leg_pos_[i] - ang < leg_pos_[leg_no] - ang){
                leg_no = i;
            }
        }
        current_right_leg_ = leg_no;
        current_back_leg_ = (leg_no+1)%3;
        current_left_leg_ = (leg_no+2)%3;


    }

private:
    step_stage current_step_stage_;
    int current_right_leg_;
    int current_left_leg_;
    int current_back_leg_;

    std::array<float, 3> leg_pos_;
    int step_len_;
};


#endif //THREE_LEGS_CONTROLLER_GENERATOR3A_HPP
