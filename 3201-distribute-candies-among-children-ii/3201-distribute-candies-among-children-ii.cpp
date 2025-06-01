class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // Total number of non-negative solutions to x + y + z = n
        auto totalSolutions = [](int n) -> long long {
            return n < 0 ? 0 : 1LL * (n + 2) * (n + 1) / 2;
        };
        long long total = totalSolutions(n);
        total -= 3 * totalSolutions(n - limit - 1);
        total += 3 * totalSolutions(n - 2 * limit - 2);
        total -= totalSolutions(n - 3 * limit - 3);

        return total;
    }
};