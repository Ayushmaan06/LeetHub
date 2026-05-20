class Solution {
public:
    bool isc(int i , int n){
        if(i>=0 && i< n)return true;
        return false;
    }
    int islandPerimeter(vector<vector<int>>& g) {
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int ans = 0, n = g.size(), m = g[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(g[i][j]){
                    for(auto[r,c] : dir){
                        int rr = r+i , cc = c+j;
                        if(isc(rr,n) && isc(cc,m) && !g[rr][cc])ans++;
                        if(!isc(rr,n) || !isc(cc,m))ans++;
                    }
                }
            }
        }
        return ans;
    }
};