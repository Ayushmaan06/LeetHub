class Solution {
public:
    int solve(vector<int>& candidates, int target, vector<int>& dp) {
        if (target == 0) {
            return 1; // Found a valid combination
        }
        if (dp[target] != -1) {
            return dp[target];
        }
        int count = 0;
        for (int num : candidates) {
            if (target - num >= 0) {
                count += solve(candidates, target - num, dp);
            }
        }
        dp[target] = count;
        return count;
    }
    
    int combinationSum4(vector<int>& candidates, int target) {
        vector<int> dp(target + 1, -1); // Initialize memoization array
        return solve(candidates, target, dp);
    }
};
