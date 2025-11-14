#define ll long long
class Solution {
public:
    ll rearrangeSticks(ll n, ll k) {
        ll mod = 1e9+7;
        vector<vector<ll>> dp(n+1LL,vector<ll>(k+1LL,-1LL));dp[1][1]=1LL;
        for(ll i = 1 ; i <= k ; i++)dp[i][i]=1;
        for(ll i = 2 ; i <= n ; i++)dp[i][1]=((i-1)*dp[i-1][1]) % mod;
        for(ll i = 3 ; i <= n ; i++){
            for(ll j = 1 ; j <= min(i,k) ; j++){
                if(dp[i][j]==-1)dp[i][j]=(dp[i-1][j-1]+(i-1)*dp[i-1][j])%mod;
            }
        }
        return dp[n][k];
    }
};

