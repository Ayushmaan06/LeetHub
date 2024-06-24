class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1; // Handle edge case for subarray starting from index 0
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0) sum %= k; // Avoid division by zero
            // Check if the same remainder has been seen before
            if (remainderIndex.count(sum)) {
                if (i - remainderIndex[sum] > 1) return true; // Ensure subarray size is at least 2
            } else {
                remainderIndex[sum] = i; // Store the first occurrence of this remainder
            }
        }
        return false;
    }
};