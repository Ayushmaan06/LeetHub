class Solution {
public:
    void backtrack(int i, int currentOr, int maxOr, vector<int>& nums, int& totalCount) {
        // If we reached the end of the array
        if (i == nums.size()) {
            // If the current OR equals the maximum OR found, increment the count
            if (currentOr == maxOr) {
                totalCount++;
            }
            return;
        }

        // Include the current number in the OR
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
