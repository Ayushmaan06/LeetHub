class Solution {
public:
int MOD = 1e9 + 7;
        
    // Modular exponentiation function
    long long modExp(long long base, long long exp, int mod) {
        long long result = 1;
        base = base % mod;  // To handle the case when base >= mod
        while (exp > 0) {
            if (exp % 2 == 1)  // If exp is odd
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {

        long long e = (n + 1) / 2; 
        long long o = n / 2;        
        
        // Apply modular exponentiation
        long long even = modExp(5, e, MOD);
        long long odd = modExp(4, o, MOD);

        return (even * odd) % MOD;
    }
};
