class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        // If out of bounds or not 'O', return
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
        
        // Mark the cell as visited
        board[r][c] = 'V';
        
        // Explore all four directions
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto [dr, dc] : directions) {
            int newRow = r + dr, newCol = c + dc;
            dfs(board, newRow, newCol);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        
        // Step 1: Mark the unsurrounded regions ('O' connected to border) with 'V'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }

        // Step 2: Flip all 'O' to 'X' and 'V' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
