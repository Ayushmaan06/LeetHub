class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m=mat[0].size();
        for(int i = 0 ; i < m ; i++){
            int s=mat[0][i];
            for(int j = 1 ; j < n ; j++){
                if(mat[j][i])mat[j][i]+=s,s=mat[j][i];
                else s=0;
            }
        }
        int ans=-1;
        for(int i = 0 ; i < n ; i++){
            sort(mat[i].rbegin(),mat[i].rend());int tans=-1;
            for(int j = 0 ; j < m ; j++){
                tans=max(tans,mat[i][j]*(j+1));
            }
            ans=max(ans,tans);
        }
        return ans;
    }
};