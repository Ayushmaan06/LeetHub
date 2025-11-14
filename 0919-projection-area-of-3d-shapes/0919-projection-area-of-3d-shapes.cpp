class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        for(vector<int> v : grid){
            int m = *max_element(v.begin(),v.end());
            ans+=m;
            int z=count(v.begin(),v.end(),0);
            ans += v.size()-z;
        }
        for(int i = 0 ; i < grid[0].size() ; i++){
            int m=-1;
            for(int j = 0 ; j < grid.size() ; j++ ){
                m=max(m,grid[j][i]);
            }
            ans+=m;
        }
        return ans;
    }
};