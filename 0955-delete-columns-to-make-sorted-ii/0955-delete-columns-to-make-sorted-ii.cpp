class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool> sorted(n, false);
        int ans = 0;
        for (int col = 0; col < m; col++) {
            bool bad = false;
            for (int i = 1; i < n; i++) {
                if (!sorted[i] && strs[i-1][col] > strs[i][col]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                ans++;
                continue;
            }
            for (int i = 1; i < n; i++) {
                if (!sorted[i] && strs[i-1][col] < strs[i][col]) {
                    sorted[i] = true;
                }
            }
        }
        return ans;
    }
};
