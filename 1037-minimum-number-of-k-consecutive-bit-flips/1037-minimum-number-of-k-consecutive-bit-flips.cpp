class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0;
        int flipEffect = 0; // Tracks the current flip effect due to previous flips
        vector<int> flipEnds(nums.size(), 0); // Use an array to mark the end of flips

        for (int i = 0; i < nums.size(); ++i) {
            // Update the current flip effect
            flipEffect ^= flipEnds[i];

            // Determine the current value after considering the flip effect
            if (nums[i] == flipEffect) { // If the current value is 0 after flipEffect
                if (i + k > nums.size()) return -1; // Not enough space to flip
                
                flips++; // Perform a flip
                flipEffect ^= 1; // Update the current flip effect
                if (i + k < nums.size()) {
                    flipEnds[i + k] ^= 1; // Mark where the effect of this flip ends
                }
            }
        }

        return flips;
    }
};
