#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1ULL;
        for (int i = 0; i < n; ++i) {
            int coin = coins[i];
            for (int j = coin; j <= amount; ++j) {
                dp[j] += dp[j - coin];
            }
        }
        return static_cast<long long>(dp[amount]);
    }
};
