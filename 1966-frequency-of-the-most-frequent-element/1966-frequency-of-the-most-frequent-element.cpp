class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long sum = 0;
        int result = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};