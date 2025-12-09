class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>>dp(n);
        dp[0].resize(1);
        dp[0][0]=t[0][0];
        for(int i = 1 ; i < n ; i++){
            dp[i].resize(t[i].size());
            dp[i][0]=dp[i-1][0]+t[i][0];
            for(int j = 1 ; j < i; j++){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+t[i][j];
            }
            dp[i][i] = dp[i-1][i-1] + t[i][i];
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};