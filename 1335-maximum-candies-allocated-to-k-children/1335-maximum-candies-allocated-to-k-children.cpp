class Solution {
public:
    bool isP(int m, long long k, vector<int>& vv) {
        long long j = 0;
        for(int v : vv) {
            j += v / m; 
        }
        return j >= k;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while(l <= r) {  
            int m = l + (r - l) / 2;
            if(isP(m, k, candies)) {
                ans = m;  
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
