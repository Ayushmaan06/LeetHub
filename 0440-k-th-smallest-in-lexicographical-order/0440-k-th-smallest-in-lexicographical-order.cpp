#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k--; // Decrement k because we start from the first number

        while (k > 0) {
            int steps = countSteps(n, current, current + 1);
            if (steps <= k) {
                current++;
                k -= steps;
            } else {
                current *= 10;
                k--;
            }
        }

        return current;
    }

private:
    int countSteps(int n, long long curr, long long next) {
        int steps = 0;
        while (curr <= n) {
            steps += min(static_cast<long long>(n) + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};