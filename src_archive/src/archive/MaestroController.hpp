

// All data are beeing set in quarter-microseconds
class Servo{
public:
    /**
     * @brief Construct a new Servo object
     * All values are set in quarter-microseconds
     * @param min minimal target value (hardware limitation)
     * @param max maximal target value (hardware limitation)
     * @param center center value (at which servo is at "zero" position)
     * @param d90 qarter- microseconds equivalent of 90
     */
    Servo(int min = 496*4, int max = 2496*4, int center = 1500*4, int d90 = 2496*4): min_t(min), max_t(max), center_t(center), d90_t(d90), target(center) {
    }

    void setTarget(int new_target);
    // TODO - settery

private:
    int min_t;
    int max_t;
    int center_t;
    int d90_t;
    int target;
};