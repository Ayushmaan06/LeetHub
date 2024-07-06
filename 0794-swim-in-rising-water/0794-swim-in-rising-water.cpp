#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        // Define a min-heap priority queue where the pair is <height, <row, col>>
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // To keep track of visited cells

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true; // Mark the starting cell as visited

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int ht = current.first, row = current.second.first, col = current.second.second;

            if (row == n - 1 && col == n - 1) return ht; // Reached the bottom-right corner

            for (auto& [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true; // Mark as visited
                    int newHt = max(grid[newRow][newCol], ht);
                    pq.push({newHt, {newRow, newCol}});
                }
            }
        }

        return -1; // Should never reach here if the grid is valid
    }
};