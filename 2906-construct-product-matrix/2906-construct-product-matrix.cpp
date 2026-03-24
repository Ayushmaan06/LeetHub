#define ll __int128
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        ll size = n * m;
        vector<ll> arr;
        for(auto &row : grid)
            for(ll x : row)
                arr.push_back(x);
        vector<ll> pref(size, 1), suff(size, 1);
        for(ll i = 1; i < size; i++)pref[i] = (pref[i-1] * arr[i-1]) % 12345;
        for(ll i = size-2; i >= 0; i--)suff[i] = (suff[i+1] * arr[i+1]) % 12345;
        vector<vector<int>> res(n, vector<int>(m));
        for(ll i = 0; i < size; i++) {
            ll val = (pref[i] * suff[i]) % 12345;
            res[i/m][i%m] = val;
        }

        return res;
    }
};