class Solution {
public:
    int concatenatedBinary(int n) {
        if(n == 1) return 1;
        int MOD = 1e9 + 7;
        long long p = 1;
        for(int i = 2; i <= n; i++){
            int x = 32 - __builtin_clz(i);  
            p = (p << x) % MOD;           
            p = (p + i) % MOD;
        }
        
        return (int)p;
    }
};