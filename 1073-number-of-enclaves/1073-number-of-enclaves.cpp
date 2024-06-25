class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        queue<pair<int,int>> q;
        int r = g.size(), c = g[0].size(), count = 0;

        // Mark boundary '1's and connected '1's with BFS and mark them as visited by setting them to 0
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i == 0 || j == 0 || i == r - 1 || j == c - 1) && g[i][j] == 1) {
                    q.push({i, j});
                    g[i][j] = 0;
                }
            }
        }

        vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        // BFS to mark all reachable '1's from the boundary
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c && g[newRow][newCol] == 1) {
                    q.push({newRow, newCol});
                    g[newRow][newCol] = 0;
                }
            }
        }

        // Count the remaining '1's which are enclaves
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
