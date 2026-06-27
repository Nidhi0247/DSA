class Solution {
public:
    double angleClock(int hour, int minutes) {
        double first_angle = abs(30*hour-5.5*minutes);
        double s_angle= abs(360-first_angle);
        return min(first_angle,s_angle);
    }
};