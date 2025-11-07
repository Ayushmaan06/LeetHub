class Solution {
public:
    long long maxPower(vector<int>& st, int r, int k) {
        int n = st.size();
        vector<long long> v(n + 1, 0); 
        for (int i = 0; i < n; i++) {
            int l = max(0, i - r);
            int h = min(n, i + r + 1);
            v[l] += st[i];
            if (h < n) v[h] -= st[i];
        }
        for (int i = 1; i < n; i++)
            v[i] += v[i - 1];
        v.pop_back(); 
        long long low = 0, high = 1e18, ans = 0;
        auto can = [&](long long x) {
            long long used = 0, currAdd = 0;
            vector<long long> diff(n + 1, 0);
            for (int i = 0; i < n; i++) {
                currAdd += diff[i];
                long long currPower = v[i] + currAdd;
                if (currPower < x) {
                    long long need = x - currPower;
                    used += need;
                    if (used > k) return false;
                    currAdd += need;
                    if (i + 2 * r + 1 < n)
                        diff[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
