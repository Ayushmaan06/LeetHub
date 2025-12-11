class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int>(a + 1, INT_MAX));
        for (int j = 0; j <= a; j++) {
            if (j % c[0] == 0)dp[0][j] = j / c[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= a; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= c[i] && dp[i][j - c[i]] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - c[i]]);
                }
            }
        }
        return dp[n - 1][a] == INT_MAX ? -1 : dp[n - 1][a];
    }
};
