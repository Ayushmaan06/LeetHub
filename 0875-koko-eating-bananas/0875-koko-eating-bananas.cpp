class Solution {
public:
    int minEatingSpeed(std::vector<int>& a, int k) {
        long long h = *std::max_element(a.begin(), a.end());
        long long l = 1;

        while (l <= h) {
            long long m = l + (h - l) / 2;
            long long totalHours = 0;

            for (auto &i : a) {
                totalHours += (i + m - 1LL) / m; // Use long long to avoid overflow
            }

            if (totalHours <= k) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return static_cast<int>(l);
    }
};