class Solution {
public:
    bool isPowerOfTwo(int t) {
        if (t <= 0) return false;
        return ((t&(t-1))==0);
    }
};
