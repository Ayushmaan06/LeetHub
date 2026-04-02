class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        
        dp[n-1][m-1][0] = coins[n-1][m-1];
        dp[n-1][m-1][1] = (coins[n-1][m-1] >= 0 ? coins[n-1][m-1] : 0);
        dp[n-1][m-1][2] = dp[n-1][m-1][1];

        for(int i = m-2 ; i >= 0 ; i--){
            dp[n-1][i][0] = dp[n-1][i+1][0] + coins[n-1][i];
            if(coins[n-1][i] < 0){
                dp[n-1][i][1] = max(dp[n-1][i+1][1] + coins[n-1][i], dp[n-1][i+1][0]);
                dp[n-1][i][2] = max(dp[n-1][i+1][2] + coins[n-1][i], dp[n-1][i+1][1]);
            }
            else {
                dp[n-1][i][1] = dp[n-1][i+1][1] + coins[n-1][i];
                dp[n-1][i][2] = dp[n-1][i+1][2] + coins[n-1][i];
            }
        }

        for(int i = n-2 ; i >= 0 ; i--){
            int c = coins[i][m-1];
            dp[i][m-1][0] = dp[i+1][m-1][0] + c;
            if(c < 0){
                for(int j = 0 ; j < 2 ; j++)dp[i][m-1][j+1] = max(dp[i+1][m-1][j+1] + c, dp[i+1][m-1][j]);
            }
            else {
                dp[i][m-1][1] = dp[i+1][m-1][1] + c;
                dp[i][m-1][2] = dp[i+1][m-1][2] + c; 
            }
        }

        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = m-2 ; j >= 0 ; j--){
                dp[i][j][0] = max(dp[i][j+1][0], dp[i+1][j][0]) + coins[i][j];
                int c = coins[i][j];
                
                if(c >= 0) {
                    dp[i][j][1] = max(dp[i][j+1][1], dp[i+1][j][1]) + c;
                    dp[i][j][2] = max(dp[i][j+1][2], dp[i+1][j][2]) + c;
                }
                else {
                    dp[i][j][1] = max(max(dp[i][j+1][1], dp[i+1][j][1]) + c, 
                                      max(dp[i][j+1][0], dp[i+1][j][0]));
                    
                    dp[i][j][2] = max(max(dp[i][j+1][2], dp[i+1][j][2]) + c, 
                                      max(dp[i][j+1][1], dp[i+1][j][1]));
                }
            }
        }
        
        return dp[0][0][2];
    }
};