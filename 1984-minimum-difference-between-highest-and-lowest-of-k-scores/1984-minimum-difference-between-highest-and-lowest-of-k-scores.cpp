class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(k==1)return 0;
        int n=nums.size(),i = 0 , j = k-1 , ans=INT_MAX;
        while(j<n)ans=min(ans,nums[j++]-nums[i++]);
        return ans;
    }
};