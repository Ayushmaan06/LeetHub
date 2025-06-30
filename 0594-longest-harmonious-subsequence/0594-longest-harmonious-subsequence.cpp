class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;){
            if(nums[i]==nums[n-1])break;
            int ns=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            int ss=ns-i;
            int nns=upper_bound(nums.begin(),nums.end(),nums[ns])-nums.begin();
            int ls=nns-ns;

            if(nums[ns]-nums[i]==1)ans=max(ls+ss,ans);
            i=ns;
        }
        return ans;
    }
};