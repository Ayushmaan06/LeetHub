class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minSum = 0, maxSum = 0, currentSum = 0;

        for (int diff : differences) {
            currentSum += diff;
            minSum = min(minSum, currentSum);
            maxSum = max(maxSum, currentSum);
        }

        long long startLower = lower - minSum;
        long long startUpper = upper - maxSum;

        return max(0LL, startUpper - startLower + 1);
    }
};