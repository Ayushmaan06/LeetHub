class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0; 
                } else {
                    grid[i][j] = -1; 
                }
            }
        }
        if (q.empty() || q.size() == n * n)
            return -1;
        vector<pair<int,int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int ans = 0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto [dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] == -1) {
                    grid[nr][nc] = grid[r][c] + 1;
                    ans = max(ans, grid[nr][nc]);
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};