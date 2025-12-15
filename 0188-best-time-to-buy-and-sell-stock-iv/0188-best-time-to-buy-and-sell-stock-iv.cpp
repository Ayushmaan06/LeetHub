class Solution {
public:
    int maxProfit(int t, vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(t+1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j >= 0; j--) {
                for (int k = t; k > 0; k--) {
                    if(j)dp[i][j][k] = max(-p[i] + dp[i+1][0][k],dp[i+1][1][k]);
                    else dp[i][j][k] = max(p[i] + dp[i+1][1][k-1],dp[i+1][0][k]);
                }
            }
        }
        return dp[0][1][t];
    }
};