class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()){
            int row = pq.top().second.first, col = pq.top().second.second , d = pq.top().first;
            pq.pop();
            if (row == n - 1 && col == m - 1)
                return d;
            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), d);

                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (newEffort < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};