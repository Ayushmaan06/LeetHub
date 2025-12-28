class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        long long l = *max_element(w.begin(), w.end());
        long long h = accumulate(w.begin(), w.end(), 0LL);
        long long ans = h;

        while (l <= h) {
            long long m = l + (h - l) / 2;

            int days = 1;
            long long curr = 0;

            for (int i : w) {
                if (curr + i > m) {
                    days++;
                    curr = 0;
                }
                curr += i;
            }

            if (days > d) {
                l = m + 1;
            } else {
                ans = m;
                h = m - 1;
            }
        }
        return (int)ans;
    }
};
