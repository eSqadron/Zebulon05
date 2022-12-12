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
        step_len_ = 50;
    }

    void set_leg_default_positions(float pos1, float pos2, float pos3){
        leg_pos_ = {pos1, pos2, pos3};
    }

    void restart_generator(){
        current_step_stage_ = Idle;
        current_right_leg_ = 0;
        current_left_leg_ = 0;
        current_back_leg_ = 0;
    }

    std::tuple<std::array<float, 2>, unsigned short int> do_step(float ang){
        calculate_right_leg(ang);
        if(current_step_stage_ ==  Idle) {
            current_step_stage_ = R_for;
        }else if(current_step_stage_ == R_for){
            current_step_stage_ = L_for;
            return std::make_tuple(calculate_endpoint_delta(ang, current_right_leg_), current_right_leg_);
        } else if(current_step_stage_ == L_for){
            current_step_stage_ = M_for;
            return std::make_tuple(calculate_endpoint_delta(ang, current_left_leg_), current_left_leg_);
        } else if(current_step_stage_ == M_for){
            current_step_stage_ = R_back;
            return std::make_tuple(calculate_endpoint_delta(ang, current_back_leg_), current_back_leg_);
        } else if(current_step_stage_ == R_back){
            current_step_stage_ = M_back;
            return std::make_tuple(calculate_endpoint_delta(ang, current_right_leg_, true), current_right_leg_);
        } else if(current_step_stage_ == M_back){
            current_step_stage_ = L_back;
            return std::make_tuple(calculate_endpoint_delta(ang, current_left_leg_, true), current_left_leg_);
        } else if(current_step_stage_ == L_back){
            current_step_stage_ = Idle;
            return std::make_tuple(calculate_endpoint_delta(ang, current_back_leg_, true), current_back_leg_);
        }

        throw std::invalid_argument("unknown stage");
    }

    std::array<float, 2> calculate_endpoint_delta(float ang, unsigned short int leg_no, bool inverse = false){
        float delta_x = step_len_ * sin(ang - leg_pos_[leg_no]);
        float delta_y = step_len_ * cos(ang - leg_pos_[leg_no]);
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

private:
    step_stage current_step_stage_;
    unsigned short int current_right_leg_;
    unsigned short int current_left_leg_;
    unsigned short int current_back_leg_;

    std::array<float, 3> leg_pos_;
    int step_len_;
};


#endif //THREE_LEGS_CONTROLLER_GENERATOR3A_HPP
