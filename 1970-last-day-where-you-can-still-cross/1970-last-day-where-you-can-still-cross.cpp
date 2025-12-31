class Solution {
public:
    bool isp(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<int>> mat(row, vector<int>(col, 0)); 
        for (int i = 0; i < day; i++) mat[cells[i][0] - 1][cells[i][1] - 1] = 1; 
        queue<pair<int, int>> q;
        for (int j = 0; j < col; j++) {
            if (mat[0][j] == 0) {
                q.push({0, j});
                mat[0][j] = 1;
            }
        }
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();            
            if (r == row - 1) return true; 
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && mat[nr][nc] == 0) {
                    mat[nr][nc] = 1; 
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 1, h = cells.size(), ans = 0;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (isp(row, col, cells, m)) {
                ans = m;     
                l = m + 1;  
            }
            else h = m - 1;
        }
        return ans;
    }
};