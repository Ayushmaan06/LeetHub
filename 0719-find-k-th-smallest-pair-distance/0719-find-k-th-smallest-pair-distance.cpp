class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }

private:
    int countPairs(const std::vector<int>& nums, int mid) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && nums[j] - nums[i] <= mid) {
                ++j;
            }
            count += j - i - 1;
        }
        return count;
    }
};