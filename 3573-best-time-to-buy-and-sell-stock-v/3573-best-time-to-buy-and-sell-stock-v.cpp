// class Solution {
// public:
//     long long maximumProfit(vector<int>& p, int t) {
//         int n = p.size();
//         vector<vector<vector<vector<long long>>>> dp(
//                                                     n+1,vector<vector<vector<long long>>>(
//                                                         t+1,vector<vector<long long>>(
//                                                             2,vector<long long>(
//                                                                 2,0
//                                                             )
//                                                         )
//                                                     ));
//         // dp[i][j][k][l] n+1,t+1,2,2 , indices , no of transactions, type , is running , 1=normal,0=ss
//         for(int i = n-1 ; i>=0 ; i--){
//             for(int j = t ; j>0 ; j--){
//                 for(int k = 1 ; k>=0 ; k--){
//                     for(int l = 1 ; l>=0 ; l--){
//                         if(!l){
//                             if(k) dp[i][j][k][l]=max(dp[i+1][j][k][l],-p[i]+dp[i+1][j][k][1]);
//                             else dp[i][j][k][l]=max(dp[i+1][j][k][l],p[i]+dp[i+1][j][k][1]); 
//                         }
//                         else{
//                             if(k)dp[i][j][k][l]=max({p[i] + dp[i+1][j-1][1][0],p[i] + dp[i+1][j-1][0][0], dp[i+1][j][1][1]});
//                             else dp[i][j][k][l]=max({-p[i]+dp[i+1][j-1][1][0],-p[i]+dp[i+1][j-1][0][0],dp[i+1][j][0][1]});
//                         }
//                     }
//                 }
//             }
//         }
//         return max(dp[0][t][0][0],dp[0][t][1][0]);
//     }
// };

class Solution {
public:
    long long maximumProfit(vector<int>& p, int t) {
        int n = p.size();
        long long INF = -1e15; 
        
        vector<vector<vector<vector<long long>>>> dp(
            n + 1, vector<vector<vector<long long>>>(
                t + 1, vector<vector<long long>>(
                    2, vector<long long>(
                        2, INF 
                    )
                )
            )
        );

        // --- CHANGE 1: Handle running out of days (Day n) ---
        for(int j = 0; j <= t; j++) {
            dp[n][j][0][0] = 0;
            dp[n][j][1][0] = 0;
        }

        // --- CHANGE 2: Handle running out of transactions (k=0) ---
        // If you have 0 transactions left, you can't make more profit.
        // This must be 0 for ALL days, not just day n.
        for(int i = 0; i <= n; i++) {
            dp[i][0][0][0] = 0;
            dp[i][0][1][0] = 0;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = t; j > 0; j--){
                for(int k = 1; k >= 0; k--){
                    for(int l = 1; l >= 0; l--){
                        if(!l){
                            if(k) dp[i][j][k][l] = max(dp[i+1][j][k][l], -p[i] + dp[i+1][j][k][1]);
                            else dp[i][j][k][l] = max(dp[i+1][j][k][l], p[i] + dp[i+1][j][k][1]); 
                        }
                        else{
                            // When this closes a transaction, it looks at j-1. 
                            // Now dp[i+1][j-1] is correctly 0 instead of INF.
                            if(k) dp[i][j][k][l] = max({p[i] + dp[i+1][j-1][1][0], p[i] + dp[i+1][j-1][0][0], dp[i+1][j][1][1]});
                            else dp[i][j][k][l] = max({-p[i] + dp[i+1][j-1][1][0], -p[i] + dp[i+1][j-1][0][0], dp[i+1][j][0][1]});
                        }
                    }
                }
            }
        }
        return max(dp[0][t][0][0], dp[0][t][1][0]);
    }
};