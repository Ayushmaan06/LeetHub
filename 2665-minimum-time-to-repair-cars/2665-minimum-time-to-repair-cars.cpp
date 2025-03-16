class Solution {
public:
    long long repairCars(vector<int>& ranks, long long cars) {
        long long left = 1, right = *min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long totalCars = 0;

            for (long long rank : ranks) {
                totalCars += floor(sqrt(mid / rank));
            }

            if (totalCars >= cars) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};