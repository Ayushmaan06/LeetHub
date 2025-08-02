class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int up = 0, b = n - 1, l = 0, r = m - 1;
        vector<int> res;
        while (up <= b && l <= r) {
            for (int i = l; i <= r; i++) {
                res.push_back(mat[up][i]);
            }
            up++;
            if (up <= b) {
                for (int i = up; i <= b; i++) {
                    res.push_back(mat[i][r]);
                }
                r--;
            }
            if (l <= r && up <= b) {
                for (int i = r; i >= l; i--) {
                    res.push_back(mat[b][i]);
                }
                b--;
            }
            if (up <= b && l <= r) {
                for (int i = b; i >= up; i--) {
                    res.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};