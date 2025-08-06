class Solution {
public:
    int sd(int x) {
        int ans = 0;
        while (x) {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        int ans = -1;  
        for (int n : nums) {
            int sumDigits = sd(n);
            mp[sumDigits].push_back(n);  
            int sz = mp[sumDigits].size();
            if (sz >= 2) {
                int a = mp[sumDigits][sz - 1];
                int b = mp[sumDigits][sz - 2];
                ans = max(ans, a + b);
            }
        }

        return ans;
    }
};
