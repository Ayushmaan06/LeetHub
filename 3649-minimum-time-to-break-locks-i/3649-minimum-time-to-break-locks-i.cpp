class Solution {
public:
    int solve(vector<int>& v, int k) {
        long long t = 0, e = 0, x = 1;
        for (int need : v) {
            if (e < need) {
                long long delta = (need - e + x - 1) / x; 
                t += delta;
            }
            e = 0;
            x += k;
        }
        return (int) t;
    }

    int findMinimumTime(vector<int>& s, int k) {
        sort(s.begin(), s.end());
        int ans = INT_MAX;
        do {
            ans = min(ans, solve(s, k));
        } while (next_permutation(s.begin(), s.end()));
        return ans;
    }
};
