#define ll __int128
class Solution {
public:
    vector<vector<int>> transpose(std::vector<std::vector<int>>& mat) {
        int n = mat.size(),m=mat[0].size();
        vector<vector<int>> g(m,vector<int>(n));
        for(int i = 0 ; i < n ; i++)
            for(int j=0;j<m;j++)
                g[j][i]=mat[i][j];
        return g;
    }
    bool check(vector<vector<int>>& grid){
        vector<ll> r;ll z=(ll)0;
        for(vector<int> g : grid) r.push_back(accumulate(g.begin(),g.end(),z));
        ll s = accumulate(r.begin(),r.end(),z),x=z;
        for(int i = 0 ; i < r.size() ; i++){
            x+=r[i];
            if(x+x==s)return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<vector<int>> g=transpose(grid);
        return (check(grid) || check(g));
    }
};