#define ll long long
class Solution {
public:
    static const ll MOD = 1000000007;

    ll specialTriplets(vector<int>& nums) {
        ll ans = 0;
        unordered_map<ll,ll> l, r;

        for (ll n : nums) r[n]++;

        for (ll n : nums) {
            r[n]--;
            ll x = 2*n;

            if (l.count(x) && r.count(x)) {
                ans = (ans + (l[x] % MOD) * (r[x] % MOD)) % MOD;
            }

            l[n]++;
        }
        return ans % MOD;
    }
};
