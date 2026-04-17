#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        int total_zeros = n - total_ones;
        
        // Map from prefix sum to list of indices where it occurs
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(0);
        int prefix = 0;
        int max_len = 0;
        
        for (int i = 1; i <= n; ++i) {
            prefix += (s[i-1] == '1') ? 1 : -1;
            
            // Case 1: Substring is already balanced (diff = 0)
            auto it = mp.find(prefix);
            if (it != mp.end()) {
                max_len = max(max_len, i - it->second[0]);
            }
            
            // Case 2: diff = 2 (2 more 1s than 0s)
            // Can fix by swapping a '1' inside with a '0' outside
            // Requires: total_zeros >= length/2, i.e., l >= i - 2*total_zeros
            auto it2 = mp.find(prefix - 2);
            if (it2 != mp.end()) {
                int bound = i - 2 * total_zeros;
                const auto& vec = it2->second;
                auto lit = lower_bound(vec.begin(), vec.end(), bound);
                if (lit != vec.end()) {
                    max_len = max(max_len, i - *lit);
                }
            }
            
            // Case 3: diff = -2 (2 more 0s than 1s)
            // Can fix by swapping a '0' inside with a '1' outside
            // Requires: total_ones >= length/2, i.e., l >= i - 2*total_ones
            auto it3 = mp.find(prefix + 2);
            if (it3 != mp.end()) {
                int bound = i - 2 * total_ones;
                const auto& vec = it3->second;
                auto lit = lower_bound(vec.begin(), vec.end(), bound);
                if (lit != vec.end()) {
                    max_len = max(max_len, i - *lit);
                }
            }
            
            mp[prefix].push_back(i);
        }
        
        return max_len;
    }
};
