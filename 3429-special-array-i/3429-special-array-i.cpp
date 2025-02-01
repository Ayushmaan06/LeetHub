class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1)  return true;
        for(int i = 1 ; i < nums.size() ; i++){
            int k = nums[i] ^ nums[i-1];
            if((k & 1) == 0){
                return false;
            }
        }
        return true;
    }
};