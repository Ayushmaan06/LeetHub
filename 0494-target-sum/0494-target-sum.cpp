class Solution {
private:
    int fun(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp, int n) {
        if (sum < 0) return 0; // Sum should not be negative
        if (idx == 0) {
            if (sum == 0 && arr[0] != 0) return 1;
            if (sum == 0 && arr[0] == 0) return 2; // If the first element is zero, it can be included or not included, hence two ways
            return (arr[0] == sum); // If the first element is equal to the sum
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        int l = 0;
        if (arr[idx] <= sum) l = fun(idx - 1, sum - arr[idx], arr, dp, n); // Take the current element

        int r = fun(idx - 1, sum, arr, dp, n); // Do not take the current element

        return dp[idx][sum] = (l + r) % 1000000007; // Store and return the result
    }
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum - t) % 2 != 0 || sum < t) return 0;
        int target = (sum - t) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fun(n - 1, target, nums, dp, n);
    }
};
