class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev_dp(n, 0);

        // Initialize with the first row
        for (int j = 0; j < n; ++j) {
            prev_dp[j] = points[0][j];
        }

        // Iterate over each row starting from the second
        for (int i = 1; i < m; ++i) {
            vector<long long> curr_dp(n, 0);
            vector<long long> left_max(n, 0), right_max(n, 0);

            // Fill left_max
            left_max[0] = prev_dp[0];
            for (int j = 1; j < n; ++j) {
                left_max[j] = max(left_max[j - 1] - 1, prev_dp[j]);
            }

            // Fill right_max
            right_max[n - 1] = prev_dp[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                right_max[j] = max(right_max[j + 1] - 1, prev_dp[j]);
            }

            // Calculate curr_dp for the current row
            for (int j = 0; j < n; ++j) {
                curr_dp[j] = points[i][j] + max(left_max[j], right_max[j]);
            }

            // Move to the next row
            prev_dp = curr_dp;
        }

        // The answer is the maximum value in prev_dp after processing all rows
        return *max_element(prev_dp.begin(), prev_dp.end());
    }
};
