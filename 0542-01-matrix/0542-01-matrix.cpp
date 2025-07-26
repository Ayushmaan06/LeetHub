class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j])mat[i][j]=INT_MAX;
                else q.push({i,j});
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()){
            auto[r,c]=q.front();q.pop();
            for(auto[rr,cc]:dir){
                int nr=r+rr,nc=c+cc;
                if(nr>=0 && nc>=0 && nr<n && nc<m && mat[r][c]+1<mat[nr][nc]){
                    mat[nr][nc]=min(mat[nr][nc],mat[r][c]+1);
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};