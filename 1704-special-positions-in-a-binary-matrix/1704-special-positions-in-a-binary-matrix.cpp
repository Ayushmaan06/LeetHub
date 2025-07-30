class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> r(n,0),c(m,0);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                r[i]+=mat[i][j];
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                c[i]+=mat[j][i];
            }
        }
        int ans=0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] && r[i]==1 && c[j]==1)ans++;
            }
        }
        return ans;
    }
};