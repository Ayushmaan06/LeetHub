class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // No jump needed if there's only one element

        int jumps = 0;        // Number of jumps needed
        int currentEnd = 0;   // The farthest index reachable within the current number of jumps
        int farthest = 0;     // The farthest index reachable

        for (int i = 0; i < n - 1; i++) {
            farthest = std::max(farthest, i + nums[i]); // Update the farthest index reachable

            if (i == currentEnd) { // If we've reached the end of the current jump range
                jumps++;           // Make a jump
                currentEnd = farthest; // Update the current end to the farthest index

                if (currentEnd >= n - 1) { // If the current end reaches or exceeds the last index
                    break;
                }
            }
        }

        return jumps;
    }
};
