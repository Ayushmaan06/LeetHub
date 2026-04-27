class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> dirs = {
            {},                 // 0: dummy
            {{0, -1}, {0, 1}},  // 1: Left, Right
            {{-1, 0}, {1, 0}},  // 2: Up, Down
            {{0, -1}, {1, 0}},  // 3: Left, Down
            {{0, 1}, {1, 0}},   // 4: Right, Down
            {{0, -1}, {-1, 0}}, // 5: Left, Up
            {{0, 1}, {-1, 0}}   // 6: Right, Up
        };
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == m - 1 && c == n - 1) return true;
            int type = grid[r][c];
            for (auto d : dirs[type]) {
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int next_type = grid[nr][nc];
                    bool connected = false;
                    for (auto nd : dirs[next_type]) {
                        if (nd.first == -d.first && nd.second == -d.second) {
                            connected = true;
                            break;
                        }
                    }
                    if (connected) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }   
        return false;
    }
};