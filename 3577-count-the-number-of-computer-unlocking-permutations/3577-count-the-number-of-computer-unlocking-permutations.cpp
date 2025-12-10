class Solution {
public:
    static const long long MOD = 1'000'000'007;

    long long factorial(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = (ans * i) % MOD;   // take modulo
        }
        return ans;
    }

    int countPermutations(vector<int>& c) {
        int mc = *min_element(c.begin(), c.end());
        int cc = 0;
        for (int x : c) if (x == mc) cc++;
        if (cc > 1) return 0;
        if (c[0] != mc) return 0;
        return factorial((int)c.size() - 1);
    }
};
