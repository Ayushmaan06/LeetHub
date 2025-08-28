class Solution {
public:
    double R, Xc, Yc;
    Solution(double radius, double x_center, double y_center) {
        R = radius;
        Xc = x_center;
        Yc = y_center;
    }
    
    vector<double> randPoint() {
        double ang = ((double)rand() / RAND_MAX) * 2 * M_PI;
        double len = sqrt((double)rand() / RAND_MAX) * R;
        double x = Xc + len * cos(ang);
        double y = Yc + len * sin(ang);
        return {x, y};
    }
};
