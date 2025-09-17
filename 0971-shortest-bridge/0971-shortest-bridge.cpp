class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<pair<int,int>> v;
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2;
                    v.push_back(q.front());
                    found = true;
                    break;
                }
            }
        }
        while (!q.empty()) {
            auto [r, col] = q.front(); q.pop();
            for (auto [dr, dc] : dir) {
                int rr = r + dr, cc = col + dc;
                if (rr >= 0 && cc >= 0 && rr < n && cc < n && grid[rr][cc] == 1) {
                    q.push({rr, cc});
                    grid[rr][cc] = 2;
                    v.push_back({rr, cc});
                }
            }
        }
        for (auto it : v) q.push(it);
        int steps = 0;
        while (!q.empty()) {
            int nn = q.size();
            for (int i = 0; i < nn; i++) {
                auto [r, col] = q.front(); q.pop();
                for (auto [dr, dc] : dir) {
                    int nr = r + dr, nc = col + dc;
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                        if (grid[nr][nc] == 1) return steps;
                        if (grid[nr][nc] == 0) {
                            q.push({nr, nc});
                            grid[nr][nc] = 2;
                        }
                    }
                }
            }
            steps += 1;
        }
        return -1;
    }
};