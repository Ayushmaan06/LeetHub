class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int k = ans + 1;
                if (i >= k && j >= k) {
                    int sum = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
                    if (sum <= threshold) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};