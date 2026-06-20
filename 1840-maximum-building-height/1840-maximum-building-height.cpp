#define ll long long
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();
        for (int i = 1; i < m; i++) {
            int d = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1],restrictions[i - 1][1] + d);
        }
        for (int i = m - 2; i >= 0; i--) {
            int d = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1],restrictions[i + 1][1] + d);
        }
        ll ans = 0;
        for (int i = 1; i < m; i++) {
            ll p1 = restrictions[i - 1][0];
            ll h1 = restrictions[i - 1][1];
            ll p2 = restrictions[i][0];
            ll h2 = restrictions[i][1];
            ll d = p2 - p1;
            ans = max(ans, (h1 + h2 + d) / 2);
        }
        ll lastPos = restrictions.back()[0];
        ll lastH   = restrictions.back()[1];

        ans = max(ans, lastH + (n - lastPos));

        return (int)ans;
    }
};