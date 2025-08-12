class Solution {
public:
    const int MOD=1e9+7;
    long long modExp(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1)
                res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
    int countSubsequences(vector<long long>& arr, int k) {
        int n = arr.size();
        vector<long long> dp(k+1, 0);
        dp[0] = 1; 
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= arr[i]; --j) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }
        return dp[k];
    }
    int numberOfWays(int n, int x) {
        vector<long long> res;
        for(int i = 1 ; ; i++){
            long long p = modExp(i, x);
            if(p > n) break;
            res.push_back(p);
        }
        int ans = countSubsequences(res, n);
        return ans;
    }
};