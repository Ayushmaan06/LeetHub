
class Solution {
public:
    bool isMagicSquare(const std::vector<std::vector<int>>& g, int row, int col) {
        std::unordered_set<int> uniqueNumbers;
        int sum = g[row][col] + g[row][col + 1] + g[row][col + 2];
        
        // Check rows
        for (int i = 0; i < 3; ++i) {
            int rowSum = 0;
            for (int j = 0; j < 3; ++j) {
                int num = g[row + i][col + j];
                if (num < 1 || num > 9 || uniqueNumbers.count(num)) return false;
                uniqueNumbers.insert(num);
                rowSum += num;
            }
            if (rowSum != sum) return false;
        }
        
        // Check columns
        for (int j = 0; j < 3; ++j) {
            int colSum = 0;
            for (int i = 0; i < 3; ++i) {
                colSum += g[row + i][col + j];
            }
            if (colSum != sum) return false;
        }
        
        // Check diagonals
        if (g[row][col] + g[row + 1][col + 1] + g[row + 2][col + 2] != sum) return false;
        if (g[row][col + 2] + g[row + 1][col + 1] + g[row + 2][col] != sum) return false;
        
        return true;
    }

    int numMagicSquaresInside(std::vector<std::vector<int>>& g) {
        int r = g.size(), c = g[0].size();
        if (r < 3 || c < 3) return 0;
        
        int count = 0;
        for (int i = 0; i <= r - 3; ++i) {
            for (int j = 0; j <= c - 3; ++j) {
                if (isMagicSquare(g, i, j)) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};