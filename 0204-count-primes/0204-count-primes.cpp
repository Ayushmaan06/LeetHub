class Solution {
public:
    int countPrimes(int n) {
        if(n>1)n--;
        vector<bool> chPrime(n + 1, true);
        int c=0;
        chPrime[0] = chPrime[1] = false;
        for (int p = 2; p * p <= n; ++p) {
            if (chPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    chPrime[i] = false;
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (chPrime[i]) {
                c++;
            }
        }

        return c;
    }
};