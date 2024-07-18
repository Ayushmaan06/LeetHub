class Solution {
public:
    int solve(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0; // If amount is 0, no coins are needed.
        if (n == 0) return INT_MAX - 1; // If no coins left, return a large number to indicate impossibility.

        if (dp[n][amount] != -1) return dp[n][amount];

        if (coins[n - 1] <= amount) {
            dp[n][amount] = min(1 + solve(n, amount - coins[n - 1], coins, dp), solve(n - 1, amount, coins, dp));
        } else {
            dp[n][amount] = solve(n - 1, amount, coins, dp);
        }

        return dp[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int result = solve(n, amount, coins, dp);
        return result == INT_MAX - 1 ? -1 : result;
    }
};