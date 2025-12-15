class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 1 ; j>=0 ; j--){
                if(j) dp[i][j]=max(-p[i] + dp[i+1][0] , dp[i+1][1]);
                else  dp[i][j]=max( p[i] + dp[i+2][1] , dp[i+1][0]);
            }
        }
        for(int i = 0 ; i <=n ; i++){
            for(int j = 0 ; j<=1 ; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[0][1];
    }
};