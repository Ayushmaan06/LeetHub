class Solution {
public:
    int solve(int i, int j1, int j2, int n, int m,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e9;
        int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int ans = curr + solve(i + 1, j1 + dj1, j2 + dj2,
                                       n, m, grid, dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size() , m=g[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // dp[0][0][0] = g[0][0];dp[0][1][m-1]=g[0][m-1];
        // // dp[0][2][0] = dp[0][0][0];dp[0][2][m-1]=dp[]
        // for(int i = 1 ; i < n ; i++){
        //     for(int j =1 ; j < m-1 ;j++){
        //         dp[i][1][j]=max({dp[i-1][1][j-1], dp[i-1][1][j], dp[i-1][1][j+1]}) + g[i][j] ;
        //         dp[i][0][j] = max({dp[i-1][0][j-1], dp[i-1][0][j], dp[i-1][0][j+1]})+ g[i][j];
        //         if(dp[i][1][j] > dp[i][0][j])dp[i][0][j]-=g[i][j];
        //         else dp[i][1][j]-=g[i][j];
        //     }
        //     dp[i][1][0] = max({ dp[i-1][1][0] , dp[i-1][1][1] }) + g[i][0] ;
        //     dp[i][0][0] = max({ dp[i-1][0][0] , dp[i-1][0][1] }) + g[i][0] ;
        //     if(dp[i][1][0] > dp[i][0][0])dp[i][0][0]-=g[i][0];
        //     else dp[i][1][0]-=g[i][0];
        //     dp[i][0][m-1] = max({dp[i-1][0][m-1-1], dp[i-1][0][m-1]})+ g[i][m-1];
        //     dp[i][1][m-1] = max({dp[i-1][1][m-1-1], dp[i-1][1][m-1]})+ g[i][m-1];
        //     if(dp[i][1][m-1] > dp[i][0][m-1])dp[i][0][m-1]-=g[i][m-1];
        //     else dp[i][1][m-1]-=g[i][m-1];
        // }
        // return (*max_element(dp[n-1][0].begin(),dp[n-1][0].end()) + *max_element(dp[n-1][1].begin(),dp[n-1][1].end()) );
        return solve(0, 0, m - 1, n, m, g, dp);

    }
};