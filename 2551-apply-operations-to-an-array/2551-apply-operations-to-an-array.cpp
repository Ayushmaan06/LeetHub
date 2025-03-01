class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i < n-1 ; i++){
            if(nums[i]==nums[i+1]){
                nums[i+1]=0;
                nums[i]+=nums[i];
            }
        }
        vector<int> ans(n,0);
        int i = 0;
        for(int num : nums){
            if(num)ans[i++]=num;
        }
        return ans;
    }
};