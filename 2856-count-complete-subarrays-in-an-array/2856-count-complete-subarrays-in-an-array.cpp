class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        unordered_set<int> distinct(nums.begin(), nums.end());
        int total_unique = distinct.size();

        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            for (int j = i; j < n; ++j) {
                seen.insert(nums[j]);
                if (seen.size() == total_unique) {
                    total++;
                }
            }
        }
        return total;
    }
};
