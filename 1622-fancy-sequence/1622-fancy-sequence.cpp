#include <vector>

class Fancy {
private:
    long long add;
    long long mult;
    const int MOD = 1e9 + 7;
    std::vector<long long> seq;

    // Helper to calculate (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper to calculate the modular inverse
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
        add = 0;
        mult = 1;
    }
    
    void append(int val) {
        // v = (val - add) / mult
        long long v = (val - add + MOD) % MOD; // +MOD to handle negative numbers
        v = (v * modInverse(mult)) % MOD;
        seq.push_back(v);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        // When we multiply all, we also multiply the previously added values
        add = (add * m) % MOD;
        mult = (mult * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) {
            return -1;
        }
        // Apply global lazy operations to the stored base value
        return (seq[idx] * mult + add) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */