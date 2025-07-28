class Solution {
public:
    void backtrack(int i, int currentOr, int maxOr, vector<int>& nums, int& totalCount) {
        if (i == nums.size()) {
            if (currentOr == maxOr) {
                totalCount++;
            }
            return;
        }
        backtrack(i + 1, currentOr | nums[i], maxOr, nums, totalCount);

        backtrack(i + 1, currentOr, maxOr, nums, totalCount);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;

        for (int num : nums) {
            maxOr |= num;
        }
        
        int totalCount = 0;

        backtrack(0, 0, maxOr, nums, totalCount);
        return totalCount;
    }
};