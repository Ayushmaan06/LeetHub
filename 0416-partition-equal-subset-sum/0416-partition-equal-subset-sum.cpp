class Solution {
public:
    int solve(vector<vector<int>>&dp, vector<int>& arr, int s, int n){
        if(n==0 || s==0) return 0;
        if(dp[n][s] != -1) return dp[n][s];
        int ans = 0;
        if(arr[n-1] > s)
            ans = solve(dp, arr, s, n-1);
        else
            ans = max(arr[n-1] + solve(dp, arr, s-arr[n-1], n-1), solve(dp, arr, s, n-1));
        return dp[n][s] = ans;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return (solve(dp, arr, sum, n) == sum);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;
        sum/=2;
        return isSubsetSum(nums,sum);
    }
};