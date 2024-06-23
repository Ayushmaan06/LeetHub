class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& m, int sr, int sc, int k) {
        if (m[sr][sc] == k) return m; // If the starting cell already has the color k, no need to proceed.
        int row = m.size(), col = m[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int originalColor = m[sr][sc];
        m[sr][sc] = k;
        while (!q.empty()) {
            auto [ro, co] = q.front();
            q.pop();
            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (auto [dr, dc] : directions) {
                int newRow = ro + dr, newCol = co + dc;
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && m[newRow][newCol] == originalColor) {
                    m[newRow][newCol] = k;
                    q.push({newRow, newCol});
                }
            }
        }
        return m;
    }
};