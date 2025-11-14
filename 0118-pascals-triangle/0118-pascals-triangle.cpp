class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        for(int j = 0; j < numRows; j++){
            v[j].resize(j + 1, 1); 
            for (int i = 1; i < j; i++) {
                v[j][i] = v[j - 1][i - 1] + v[j - 1][i];
            }
        }
        return v;
    }
};