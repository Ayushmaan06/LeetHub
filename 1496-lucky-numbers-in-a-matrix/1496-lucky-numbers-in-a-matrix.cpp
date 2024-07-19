class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> luckyNums;
    int m = matrix.size(), n = matrix[0].size();
    
    for (int i = 0; i < m; ++i) {
        // Find the minimum element in the current row.
        int minRow = *min_element(matrix[i].begin(), matrix[i].end());
        int minColIndex = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
        
        // Assume the current minimum is a lucky number.
        bool isLucky = true;
        
        // Check if it's the maximum in its column.
        for (int j = 0; j < m; ++j) {
            if (matrix[j][minColIndex] > minRow) {
                isLucky = false;
                break;
            }
        }
        
        // If it's a lucky number, add it to the result.
        if (isLucky) {
            luckyNums.push_back(minRow);
        }
    }
    
    return luckyNums;
}
};