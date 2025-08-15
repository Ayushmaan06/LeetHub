class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        vector<pair<int,int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while (!pq.empty()) {
            auto [currMax, r, c] = pq.top();
            pq.pop();
            if (r == n - 1 && c == n - 1)
                return currMax;
            for (auto [dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int nextMax = max(currMax, grid[nr][nc]);
                    pq.push({nextMax, nr, nc});
                }
            }
        }
        return -1; 
    }
};