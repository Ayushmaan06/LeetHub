class Solution {
public:
    bool solve(int r, int c, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
        // Base cases
        if (index == word.length()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visited[r][c] || board[r][c] != word[index]) {
            return false;
        }

        // Mark the cell as visited
        visited[r][c] = true;

        // Explore all possible directions
        bool found = solve(r - 1, c, index + 1, board, word, visited) || // Up
                     solve(r + 1, c, index + 1, board, word, visited) || // Down
                     solve(r, c - 1, index + 1, board, word, visited) || // Left
                     solve(r, c + 1, index + 1, board, word, visited);   // Right

        // Backtrack
        visited[r][c] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && solve(i, j, 0, board, word, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};
