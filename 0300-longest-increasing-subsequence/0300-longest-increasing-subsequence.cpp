class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // set<int> t(nums.begin(),nums.end());
        // vector<int> r(t.begin(),t.end()) ;
        // // sort(r.begin(),r.end());
        // int n = r.size(),m=nums.size();
        // for(int i : r)cout<<i<<" ";cout<<endl;
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0)); 
        // for(int i = 1 ; i <= m ; i++){
        //     for(int j = 1 ; j <= n ; j++){
        //         if(nums[i-1] == r[j-1])dp[i][j]=dp[i-1][j-1]+1;
        //         else dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
        //     }
        // }
        // int i = m,j=n;
        // while(i>0 && j>0){
        //     if(nums[i-1] == r[j-1]){i--;j--;cout<<nums[i]<<" ";}
        //     else{
        //         if(dp[i-1][j] > dp[i][j-1])i--;
        //         else j--;
        //     }
        // }
        // return dp[m][n];
        if(nums.size() == 0) return nums.size();
        vector<int> tails;

        for(int i=0; i<nums.size(); i++) {
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if(it == tails.end()) {
                tails.push_back(nums[i]);
            } else  {
                *it = nums[i];
            }
        }

        return (int) tails.size();
    }
};