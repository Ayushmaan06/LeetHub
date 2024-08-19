class Solution {
public:
    vector<int> precomputeMinOperations(int maxN) {
        vector<int> dp(maxN + 1, INT_MAX);
        dp[1] = 0; // Base case: 0 operations needed to get 1 'A'

        for (int i = 2; i <= maxN; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i / j);
                    if (j != 1) {
                        dp[i] = min(dp[i], dp[i / j] + j);
                    }
                }
            }
        }

        return dp;
    }

    int minSteps(int n) {
        vector<int> dp = precomputeMinOperations(n);
        return dp[n];
    }
};
