class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(n, vector<bool>(m, false)), atl(n, vector<bool>(m, false));
        queue<pair<int, int>> qp, qa;
        for (int i = 0; i < n; ++i) {
            qp.push({i, 0});
            qa.push({i, m - 1});
            pac[i][0] = true;
            atl[i][m - 1] = true;
        }
        for (int j = 0; j < m; ++j) {
            qp.push({0, j});
            qa.push({n - 1, j});
            pac[0][j] = true;
            atl[n - 1][j] = true;
        }
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
            vector<int> dirs = {0, 1, 0, -1, 0};
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d], ny = y + dirs[d + 1];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && h[nx][ny] >= h[x][y]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        };
        bfs(qp, pac);
        bfs(qa, atl);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
        return res;
    }
};
