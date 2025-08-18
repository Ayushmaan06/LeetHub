class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int n = grid.size(),m=grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    for(auto [r,c] : dir){
                        int rr=r+i,cc=c+j;
                        if(rr<0 || cc<0 ||rr>=n ||cc>=m )ans++;
                        else{
                            if(grid[rr][cc]==0)ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};