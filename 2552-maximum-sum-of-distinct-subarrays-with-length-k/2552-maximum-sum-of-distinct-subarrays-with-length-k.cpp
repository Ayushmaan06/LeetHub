class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0, currentSum = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int l = 0;

        for (int r = 0; r < n; ++r) {
            freq[nums[r]]++;
            currentSum += nums[r];
            while (freq[nums[r]] > 1) {
                currentSum -= nums[l];
                freq[nums[l]]--;
                l++;
            }
            if (r - l + 1 == k) {
                maxSum = max(maxSum, currentSum);
                currentSum -= nums[l];
                freq[nums[l]]--;
                l++;
            }
        }

        return maxSum;
    }
};
