class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0,ans = 1;
        for (int j = 0; j < n; j++) {
            while (i <= j && nums[j] > (long long)k * nums[i]) i++;
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};
