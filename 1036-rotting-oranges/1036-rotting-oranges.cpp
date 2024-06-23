#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q; // Queue to store rotten oranges (row, col)
        int freshOranges = 0, minutes = 0;
        
        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) freshOranges++;
            }
        }
        
        // Directions: up, right, down, left
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // BFS traversal
        while (!q.empty() && freshOranges > 0) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [row, col] = q.front(); q.pop();
                for (auto [dr, dc] : directions) {
                    int newRow = row + dr, newCol = col + dc;
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2; // Make it rotten
                        freshOranges--;
                        q.push({newRow, newCol});
                    }
                }
            }
            minutes++; // Increase minutes after processing all oranges at the current minute
        }
        
        return freshOranges == 0 ? minutes : -1;
    }
};