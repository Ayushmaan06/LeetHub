class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == weights.size()) return 0;

        vector<long long> gaps;
        for (int i = 0; i < weights.size() - 1; ++i) {
            gaps.push_back(weights[i] + weights[i + 1]);
        }

        sort(gaps.begin(), gaps.end());

        long long maxScore = 0;
        for (int i = gaps.size() - k + 1; i < gaps.size(); ++i) {
            maxScore += gaps[i];
        }

        long long minScore = 0;
        for (int i = 0; i < k - 1; ++i) {
            minScore += gaps[i];
        }

        return maxScore - minScore;
    }
};
