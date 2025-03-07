#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    // Function to get all primes up to n using the Sieve of Eratosthenes
    vector<int> SieveOfEratosthenes(int n) {
        vector<int> ans;
        vector<bool> prime(n + 1, true);
        
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }

        // Collect all primes in the result vector
        for (int p = 2; p <= n; p++) {
            if (prime[p]) {
                ans.push_back(p);
            }
        }
        return ans;
    }

    vector<int> closestPrimes(int left, int right) {
        // Get all primes up to right
        vector<int> primes = SieveOfEratosthenes(right);

        // Find the index of the first prime >= left
        int it = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        int n = primes.size();

        // If there are no primes in the range, return [-1, -1]
        if (it >= n) return {-1, -1};

        int minDiff = INT_MAX;
        vector<int> ans = {-1, -1};

        // Check pairs of consecutive primes
        for (int i = it; i < n - 1; i++) {
            if (primes[i + 1] - primes[i] < minDiff) {
                minDiff = primes[i + 1] - primes[i];
                ans[0] = primes[i];
                ans[1] = primes[i + 1];
            }
        }

        return ans;
    }
};
