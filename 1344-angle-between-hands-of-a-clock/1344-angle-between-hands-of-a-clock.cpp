class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 30*hour + minutes*0.5, m = 6*minutes, d = abs(h-m);
        return min(d,360-d);
    }
};