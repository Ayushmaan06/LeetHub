class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& kia) {
        int m = kia.size(),n = kia[0].size();
        for (int i = 0; i < m; ++i) {
            int vw = n - 1; 
            for (int j = n - 1; j >= 0; --j) {
                if (kia[i][j] == '*') {
                    vw = j - 1;
                } else if (kia[i][j] == '#') {
                    kia[i][j] = '.';
                    kia[i][vw] = '#';
                    vw--; 
                }
            }
        }
        vector<vector<char>> bmw(n, vector<char>(m));
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) bmw[j][m - 1 - i] = kia[i][j];
            
        return bmw;
    }
};