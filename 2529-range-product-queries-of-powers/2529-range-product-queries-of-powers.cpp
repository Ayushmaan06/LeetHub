class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modExp(long long base, long long exp, int mod) {
        long long res = 1;
        base %= mod;
        while(exp > 0) {
            if(exp & 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> p;
        for (int i = 0; i < 31; i++) {
            if ((n & (1 << i)) == (1 << i))
                p.push_back(1LL << i);
        }
        vector<long long> pr(p.size(), 1);
        pr[0] = p[0] % MOD;
        for (int i = 1; i < p.size(); i++) {
            pr[i] = (pr[i - 1] * p[i]) % MOD;
        }
        vector<int> res;
        for (auto &q : queries) {
            int st = q[0], en = q[1];
            long long ans;
            if(st > 0) {
                long long inv = modExp(pr[st - 1], MOD - 2, MOD);
                ans = (pr[en] * inv) % MOD;
            } else {
                ans = pr[en];
            }
            res.push_back((int)ans);
        }
        return res;
    }
};