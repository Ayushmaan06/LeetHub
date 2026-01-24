class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i =0,n=nums.size(),j=n-1,ans=INT_MIN;
        while(i<j){
            int s = nums[i++]+nums[j--];
            ans=max(ans,s);
        }
        return ans;
    }
};