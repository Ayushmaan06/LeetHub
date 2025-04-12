class Solution {
    long long vectorToNumber(const vector<int>& nums) {
        long long res = 0;
        for (int dig : nums) res = res * 10 + dig;
        return res;
    }

    long long fact(int total, long long f = 1) {
        for (int i = 2; i <= total; i++) f *= i;
        return f;
    }

    long long totalPermutations(map<int, int>& mpp, int total) {
        long long totalDig = fact(total);
        for (auto& palinVal : mpp) totalDig /= fact(palinVal.second);
        return totalDig;
    }

    long long permsWithZero(map<int, int> mpp, int total) {
        return mpp[0] == 0 ? 0 : ([&]() {
            mpp[0]--;
            long long tot = fact(total - 1);
            for (auto& palinVal : mpp)
                tot /= fact(palinVal.second);
            return tot;
        }());
    }

public:
    long long res = 0;
    set<map<int, int>> visited;

    void genPal(vector<int>& palin, int left, int right, int divisor, int total) {
        if (left > right) {
            long long palinVal = vectorToNumber(palin);
            if (palinVal % divisor == 0) {
                map<int, int> digMpp;
                for (long long result = palinVal; result; result /= 10)
                    digMpp[result % 10]++;
                if (!visited.count(digMpp)) {
                    res += totalPermutations(digMpp, total) - permsWithZero(digMpp, total);
                    visited.insert(digMpp);
                }
            }
            return;
        }
        for (int dig = (left == 0 ? 1 : 0); dig <= 9; dig++) {
            palin[left] = palin[right] = dig;
            genPal(palin, left + 1, right - 1, divisor, total);
        }
    }

    long long countGoodIntegers(int total, int divisor) {
        vector<int> palin(total);
        genPal(palin, 0, total - 1, divisor, total);
        return res;
    }
};