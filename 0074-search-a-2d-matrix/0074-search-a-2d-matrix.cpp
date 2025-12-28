class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        if (n == 0) return false;
        int c = mat[0].size(),l = 0, h = n - 1,ansl = -1, ansh = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (mat[m][0] <= t) {
                ansl = m;
                l = m + 1;
            } 
            else h = m - 1;  
        }
        l = 0; h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (mat[m][c - 1] >= t) {
                ansh = m;
                h = m - 1;
            } 
            else l = m + 1;
        }
        if (ansl == -1 || ansh == -1) return false;
        for (int i = ansh; i <= ansl; i++) {
            if (binary_search(mat[i].begin(), mat[i].end(), t))
                return true;
        }
        return false;
    }
};
