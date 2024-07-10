class Solution {
public:
    int solve(vector<int>&dp , int n){
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solve(dp , n-1)+solve(dp , n-2);
    }
    int fib(int n) {
        vector<int> dp(n+2 , -1);
        dp[0]=0; dp[1]=1;
        return solve(dp,n);
    }
};