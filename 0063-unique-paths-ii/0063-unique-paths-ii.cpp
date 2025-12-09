class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size(),m=o[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1));
        if(o[0][0])return 0;
        if(n==1){
            for(int i = 0 ; i < m ; i++){
                if(o[0][i])return 0;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(o[i][0]){
               while(i<n)dp[i++][0]=0;
            }
        }
        for(int i = 0 ; i < m ; i++){
             if(o[0][i]){
               while(i<m)dp[0][i++]=0;
            }
        }
        for(int i = 1; i < n ; i++){
            for(int j= 1 ; j< m ; j++){
                if(o[i][j])dp[i][j]=0;
                // else if(j==0)dp[i][j]=dp[i][j-1];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};