class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1)return 0;
        int l = 0 , r = 0;
        int p = 1;
        int ans=0;
        while(r<n){
            p*=nums[r];
            while(p>=k){
                p/=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};