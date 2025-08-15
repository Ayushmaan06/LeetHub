class Solution {
public:
    double log_a_to_base_b(double a, double b)
    {
        return log2(a) / log2(b);
    }
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        double x = log_a_to_base_b(n,4);
        const double eps = 1e-10;
        return abs(x - round(x)) < eps;
    }
};