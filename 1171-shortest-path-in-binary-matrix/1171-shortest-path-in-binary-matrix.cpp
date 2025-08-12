class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; 
        if(n == 1) return 1; 
        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; 
        int pathLength = 1;

        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();
                if(row == n-1 && col == n-1) return pathLength; 
                for(const auto& [dr, dc] : directions) {
                    int newRow = row + dr, newCol = col + dc;
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 1; 
                    }
                }
            }
            ++pathLength;
        }
        return -1; 
    }
};