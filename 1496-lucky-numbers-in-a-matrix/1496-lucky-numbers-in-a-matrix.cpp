class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> r(n,INT_MAX),c(m,INT_MIN),res;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                r[i]=min(r[i],mat[i][j]);
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                c[i]=max(c[i],mat[j][i]);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j]==r[i]&& r[i]==c[j])res.push_back(mat[i][j]);
            }
        }
        return res;
    }
};