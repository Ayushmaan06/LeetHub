

class Solution {
public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());

        if (static_cast<long long>(k) * m > n) return -1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int flowers = 0, bouquets = 0;

            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] > mid) {
                    flowers = 0;
                } else if (++flowers >= k) {
                    bouquets++;
                    flowers = 0;
                }
            }

            if (bouquets < m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};