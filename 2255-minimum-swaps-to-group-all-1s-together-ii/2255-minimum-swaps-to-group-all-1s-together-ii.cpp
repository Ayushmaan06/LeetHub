class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int c = 0; // Total number of 1s in the array

        // Count the total number of 1s
        for (int num : nums) {
            if (num == 1) c++;
        }

        // If there are no 1s or the entire array is 1s, no swaps are needed
        if (c == 0 || c == n) return 0;

        int maxOnesInWindow = 0;
        int currentOnesInWindow = 0;
        int i = 0;

        // Use a sliding window to find the maximum number of 1s in any subarray of length c
        for (int j = 0; j < 2 * n; ++j) {
            if (nums[j % n] == 1) currentOnesInWindow++;

            if (j - i + 1 > c) {
                if (nums[i % n] == 1) currentOnesInWindow--;
                i++;
            }

            maxOnesInWindow = max(maxOnesInWindow, currentOnesInWindow);
        }

        // The minimum number of swaps required
        return c - maxOnesInWindow;
    }
};