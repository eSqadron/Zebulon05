#include <array>

class ServoJoint{
    public: 
        virtual void move_servo(double target) = 0;
        virtual double get_servo_angle() = 0;

};


class RobotLeg{
    private:
        const std::array<unsigned int, 4> joint_distances;
        const unsigned int h0;
        const unsigned int h1;

        const static unsigned int num_of_servos = 3;

        ServoJoint* servo0{};
        ServoJoint* servo1{};
        ServoJoint* servo2{};

        ServoJoint* servos[num_of_servos] = {servo0, servo1, servo2};

    protected:
        /**
         * @brief calculate forward kinematics for a leg (endpoint position based on servo angles)
         * 
         * @param angles specific servo angles (in radians)
         * @return std::array<int, 3> 
         */
        std::array<int, 3> forward_kinematics(std::array<int, num_of_servos> angles) const;
        /**
         * @brief calculate inverse kinematics for a leg (specific angles on servos based on desired endpoint)
         * 
         * @param endpoint_position position of an endpoint (X, Y, Z) in relation to the center of the robot
         * @return std::array<int, 3> 
         */
        std::array<int, num_of_servos> inverse_kinematics(std::array<int, 3> endpoint_position) ;
    public:
        // distance between center of the robot and "0" servo
        // distance between "0" servo axis and "1" servo
        RobotLeg(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int h0, unsigned int h1) : joint_distances{{a0, a1, a2, a3}}, h0(h0), h1(h1) {};
        RobotLeg() : RobotLeg(0, 0, 0, 0, 0, 0) {};

        
        void set_servo(ServoJoint* new_servo, unsigned int servo_num);
        std::array<int, num_of_servos> get_current_angles() const;

        /**
         * Get current position endpoint position (position of the tip of the leg)
         * @return X, Y, Z array with current leg position
         */
        std::array<int, 3> get_current_endpoint_pos() const;

        void do_step(const int step_length, const int step_height, const int step_angle=0, const unsigned int interpolation=0);
        void move_to_pos(const std::array<int, 3> endpoint_position);

};