class Solution {
public:
    std::vector<int> primeFactors(int n) {
        std::vector<int> factors;

        // Divide n by 2 until it is odd
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }

        // Check for odd factors from 3 to sqrt(n)
        for (int i = 3; i <= std::sqrt(n); i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }

        // If n is still greater than 2, it must be a prime number
        if (n > 2) {
            factors.push_back(n);
        }

        return factors;
    }
    int minSteps(int n) {
        vector<int> pf = primeFactors(n);
        return accumulate(pf.begin() , pf.end() , 0); 
    }
};