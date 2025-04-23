class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int sum = total / 2;
        int n = nums.size();
        // vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // // Initialize: 0 sum is always possible
        // for (int i = 0; i <= n; i++) dp[i][0] = true;

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= sum; j++) {
        //         if (nums[i - 1] <= j)
        //             dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        //         else
        //             dp[i][j] = dp[i - 1][j];
        //     }
        // }

        // return dp[n][sum];
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        for(int num : nums){
            for(int j = sum ; j>=num ; j--){
                dp[j]=dp[j]||dp[j-num];
            }
        }
        return dp[sum];
    }
};
