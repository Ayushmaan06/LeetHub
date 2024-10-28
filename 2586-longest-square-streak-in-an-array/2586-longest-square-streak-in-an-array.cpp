class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxLength = -1;

        for (long long num : nums) {
            int length = 1;
            long long current = num;
            while (numSet.find(current * current) != numSet.end()) {
                current = current * current;
                length++;
            }
            if (length >= 2) {
                maxLength = std::max(maxLength, length);
            }
        }

        return maxLength;
    }
};