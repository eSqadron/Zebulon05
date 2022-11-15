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
    }

    void set_leg_default_positions(int pos1, int pos2, int pos3){
        leg_pos_ = {pos1, pos2, pos3};
    }

    void restart_generator(){
        current_step_stage_ = Idle;
        current_right_leg_ = 0;
    }

    void do_step(int ang){
        if(current_step_stage_ == Idle){
            calculate_right_leg(ang);
            TODO - znaleźć i przeliczyć ten kąt!!!
        }

    }

    void calculate_right_leg(int ang){
        int leg_no = 1;
        for (int i = 1; i < 3; ++i) {
            if(leg_pos_[i] - ang < leg_pos_[leg_no-1] - ang){
                leg_no = i+1;
            }
        }
        current_right_leg_ = leg_no;
    }

private:
    step_stage current_step_stage_;
    int current_right_leg_;
    std::array<int, 3> leg_pos_;
};


#endif //THREE_LEGS_CONTROLLER_GENERATOR3A_HPP
