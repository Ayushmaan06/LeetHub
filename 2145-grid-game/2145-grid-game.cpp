class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> t(n, 0), b(n, 0);
        t[0] = grid[0][0];
        b[0] = grid[1][0];
        for (int i = 1; i < n; i++){
            t[i] = t[i-1] + grid[0][i];
            b[i] = b[i-1] + grid[1][i];
        }
        long long ans = t[n-1] - t[0];
        for (int i = 1; i < n; i++){
            ans = min(ans, max(b[i-1], t[n-1] - t[i]));
        }
        return ans;
    }
};