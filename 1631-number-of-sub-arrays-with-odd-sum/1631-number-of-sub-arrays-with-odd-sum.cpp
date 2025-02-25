class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + arr[i];
        }
        int oc = 0, ec = 0, ans = 0;
        for (int i = 1; i < n + 1; i++) {
            if (ps[i] % 2) {
                oc++; 
                ans++;
                ans += ec;
            } else {
                ec++; 
                ans += oc;
            }
            ans %= mod;  // Make sure ans stays within mod
        }
        return ans;
    }
};
