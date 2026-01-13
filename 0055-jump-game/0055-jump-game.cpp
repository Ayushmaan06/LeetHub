class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =  nums.size(),nxt=n-1;
        vector<bool> dp(n,false);
        dp[n-1]=true;
        for(int i = n-2 ; i >=0 ; i--){
            int nxt1 = i+nums[i];
            if(nxt<=nxt1)dp[i]=true,nxt=i;
        }
        return dp[0];
    }
};
