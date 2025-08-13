class Solution {
public:
    // double log_a_to_base_b(double a, double b)
    // {
    //     return log2(a) / log2(b);
    // }
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return (1162261467%n == 0);
    }
};
