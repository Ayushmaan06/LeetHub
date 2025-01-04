class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long ls=0,rs=0,n=nums.size();
        int ans=0;
       for(int i = 1; i < n ; i++) {
            ls+=nums[i-1];
       }
       rs=nums[n-1];
       for(int i=n-1;i>0;i--){
        if(i!=n-1){
            ls-=nums[i];
            rs+=nums[i];
        }
        if(ls>=rs)ans++;
        
       }
        return ans;
    }
};