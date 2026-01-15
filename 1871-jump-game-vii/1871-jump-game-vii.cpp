class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length(), f = 0;
        if (s[n - 1] == '1') return false;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            int mx = min(i + maxJump, n - 1);
            for (int j = max(i + minJump, f + 1); j <= mx; ++j) {
                if (s[j] == '0') {
                    if (j == n - 1) return true;
                    q.push(j);
                }
            }
            f = max(f, mx);
        }
        return false;
    }
};