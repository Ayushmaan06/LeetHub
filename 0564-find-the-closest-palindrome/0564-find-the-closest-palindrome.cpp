class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        vector<long long> candidates;

        candidates.push_back(pow(10, len - 1) - 1); // 999...999
        candidates.push_back(pow(10, len) + 1);     // 100...001

        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string pal = p + string(p.rbegin() + (len % 2), p.rend());
            candidates.push_back(stoll(pal));
        }

        long long closest = -1;
        for (long long cand : candidates) {
            if (cand != num) {
                if (closest == -1 ||
                    abs(cand - num) < abs(closest - num) ||
                    (abs(cand - num) == abs(closest - num) && cand < closest)) {
                    closest = cand;
                }
            }
        }

        return to_string(closest);
    }
};