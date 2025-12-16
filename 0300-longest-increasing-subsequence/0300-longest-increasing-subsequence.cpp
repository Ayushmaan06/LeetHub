class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> t(nums.begin(),nums.end());
        vector<int> r(t.begin(),t.end()) ;
        // sort(r.begin(),r.end());
        int n = r.size(),m=nums.size();
        for(int i : r)cout<<i<<" ";cout<<endl;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); 
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(nums[i-1] == r[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};