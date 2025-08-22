class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minx=INT_MAX,maxx=-1,n=grid.size(),m=grid[0].size();
        int miny=minx,maxy=maxx;
        for(int i = 0 ; i < n ; i++){
            for(int j=0; j<m ; j++){
                if(grid[i][j]){
                    minx=min(minx,i);maxx=max(maxx,i);miny=min(miny,j);maxy=max(maxy,j);
                }
            }
        }
        return ((maxx-minx+1)*(maxy-miny+1));
    }
};