class Solution {
public:
    long long xc2(int x) {
        return 1LL * x * (x - 1) / 2;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> y;
        vector<int> v;
        for (vector<int>& p : points) y[p[1]]++;
        if (y.size() <= 1) return 0;
        for (auto& it : y) {
            if (it.second > 1) v.push_back(it.second);
        }
        if (v.size() <= 1) return 0;
        long long mod = 1e9 + 7, ans = 0, current_sum = 0;
        for (int i : v) {
            long long pairs = xc2(i);
            ans = (ans + pairs * current_sum) % mod;
            current_sum = (current_sum + pairs) % mod;
        }
        
        return ans;
    }
};