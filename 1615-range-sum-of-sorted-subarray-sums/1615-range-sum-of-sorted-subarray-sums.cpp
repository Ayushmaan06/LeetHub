class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> ps(n * (n + 1) / 2);
        int ind = 0;
        for (int i = 0; i < n; i++) {
            int flag = 1;
            for (int j = i; j < n; j++) {
                if (flag) {
                    ps[ind++] = nums[j] % MOD;
                    flag = 0;
                } else {
                    ps[ind] = (nums[j] + ps[ind - 1]) % MOD;
                    ind++;
                }
            }
        }
        sort(ps.begin(), ps.end());
        int sum = 0;
        for (int i = left - 1; i < right; i++) {
            sum = (sum + ps[i]) % MOD;
        }
        return sum;
    }
};
