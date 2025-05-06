class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int i = 0;
        for(int n : nums){
            ans[i++]=nums[n];
        }
        return ans;
    }
};