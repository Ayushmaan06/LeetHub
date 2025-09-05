class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 100; ++k) {
            long long s = (long long)num1 - (long long)num2 * k;
            if (s < k) continue;
            if (__builtin_popcountll(s) <= k && s >= k)
                return k;
        }
        return -1;
    }
};