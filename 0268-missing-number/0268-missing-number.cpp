class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            while(i!=nums[i] && nums[i]<nums.size())swap(nums[nums[i]],nums[i]);
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(i!=nums[i])return i;
        }
        return nums.size();
    }
};