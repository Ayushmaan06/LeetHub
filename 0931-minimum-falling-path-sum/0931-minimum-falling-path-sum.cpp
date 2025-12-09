class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0 ; i < m ; i++)dp[0][i]=mat[0][i];
        for(int i =1 ; i < n ; i++){
            for(int j = 1; j < m-1 ; j++){
                dp[i][j] = mat[i][j] + min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
            }
            dp[i][0]=mat[i][0] + min(dp[i-1][0],dp[i-1][1]);
            dp[i][m-1]=mat[i][m-1] + min(dp[i-1][m-1],dp[i-1][m-2]);
        }
        return *min_element(dp[n-1].begin() , dp[n-1].end());
    }
};