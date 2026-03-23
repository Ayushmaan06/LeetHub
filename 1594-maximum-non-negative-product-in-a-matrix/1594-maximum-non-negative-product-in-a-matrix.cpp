#define ll long long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        ll n = grid.size(),m=grid[0].size(),mod=1e9+7;
        vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll>>(m));
        dp[0][0].first=grid[0][0];dp[0][0].second=grid[0][0];
        for(ll i = 1 ; i < n ; i++)dp[i][0].first=grid[i][0]*dp[i-1][0].first,dp[i][0].second=dp[i][0].first;
        for(ll i = 1 ; i < m ; i++)dp[0][i].first=grid[0][i]*dp[0][i-1].first,dp[0][i].second=dp[0][i].first;
        for(ll i =1 ; i < n ; i++)
            for(ll j =1 ; j < m ; j++)dp[i][j].first=max({dp[i-1][j].first*grid[i][j], dp[i-1][j].second*grid[i][j], dp[i][j-1].first*grid[i][j], dp[i][j-1].second*grid[i][j]}),dp[i][j].second=min({dp[i-1][j].first*grid[i][j], dp[i-1][j].second*grid[i][j], dp[i][j-1].first*grid[i][j], dp[i][j-1].second*grid[i][j]});
        
        if(dp[n-1][m-1].first>=0)return (ll)((ll)dp[n-1][m-1].first %mod);
        if(dp[n-1][m-1].second>=0)return (ll)((ll)dp[n-1][m-1].second %mod);
        return -1;
    }
};