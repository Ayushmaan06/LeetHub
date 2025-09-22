class Solution {
public:
    long long minEnd(int n, int x) {
        long long i = 0LL, ix = 0LL; 
        long long r = n - 1LL;      
        long long ans = x;  
        while (i < 64) {
            if (ix >= 64) {
                break;  
            }
            long long z = x & (1LL << ix);  
            if (!z) {  
                long long y = r & (1LL << i);   
                if (y) {
                    ans = ans | (1LL << ix);
                }
                i++;
            }
            ix++;  
        }
        return ans;  
    }
};
