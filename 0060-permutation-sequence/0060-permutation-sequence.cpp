class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        k--; 
        string res = "";
        for (int i = n; i >= 1; i--) {
            int f = fact[i-1];
            int idx = k / f;
            k %= f;
            res += char('0' + nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return res;
    }
};
