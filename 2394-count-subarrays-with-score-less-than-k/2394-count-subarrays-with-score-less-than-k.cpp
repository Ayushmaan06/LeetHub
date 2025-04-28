class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        vector<long long> ps(n + 1, 0);
        for (long long i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + nums[i - 1];
        }
        long long ans = 0;
        for (long long i = 1; i <= n; i++) {
            long long l = 0, r = i - 1;
            long long cn = ps[i];
            long long res = -1;  // Initialize res properly
            while (l <= r) {
                long long m = l + (r - l) / 2;
                if (k > (cn - ps[m]) * (i - m)) {
                    res = m;    
                    r = m - 1;  
                } else {
                    l = m + 1;
                }
            }
            if (res != -1) ans += (i - res);
        }
        return ans;
    }
};
