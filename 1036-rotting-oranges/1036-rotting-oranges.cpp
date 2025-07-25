class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fo=0;
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0 ;i < n ; i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)fo++;
            }
        }
        int min=0;
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while(!q.empty() && fo>0){
            int nn = q.size();
            for(int i = 0 ; i < nn ; i++){
                auto[r,c]=q.front();q.pop();
                for(auto [nr,nc] : dir){
                    int rr=r+nr,cc=c+nc;
                    if(rr>=0 && rr<n && cc>=0 && cc<m && grid[r+nr][c+nc]==1){
                        grid[r+nr][c+nc]=2;
                        fo--;
                        q.push({r+nr,c+nc});
                    }
                }
            }
            min++;
        }
        if(fo)return -1;
        return min;
    }
};