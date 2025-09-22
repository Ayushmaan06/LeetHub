class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int total = nums.size();
        int n = total / 2;
        int totalSum = 0;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());
        vector<vector<int>> leftSums(n + 1);
        vector<vector<int>> rightSums(n + 1);

        generateSubsets(left, leftSums);
        generateSubsets(right, rightSums);
        int result = INT_MAX;
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        for (int k = 0; k <= n; k++) {
            auto& l = leftSums[k];
            auto& r = rightSums[n - k];
            sort(r.begin(), r.end());

            for (int sumLeft : l) {
                int target = (totalSum / 2) - sumLeft;

                auto it = lower_bound(r.begin(), r.end(), target);

                if (it != r.end()) {
                    int sumRight = *it;
                    int currentSum = sumLeft + sumRight;
                    result = min(result, abs(totalSum - 2 * currentSum));
                }
                if (it != r.begin()) {
                    --it;
                    int sumRight = *it;
                    int currentSum = sumLeft + sumRight;
                    result = min(result, abs(totalSum - 2 * currentSum));
                }
            }
        }


        return result;
    }

private:
    void generateSubsets(vector<int>& nums, vector<vector<int>>& subsetSums) {
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            int bitCount = __builtin_popcount(i);
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum += nums[j];
                }
            }
            subsetSums[bitCount].push_back(sum);
        }
    }
};
