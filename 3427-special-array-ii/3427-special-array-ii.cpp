#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> ans;
        vector<int> prefixHasEvenXor(n + 1, 0);

        // Preprocess to find if there's any even XOR up to each position
        for (int i = 1; i < n; ++i) {
            int k = nums[i] ^ nums[i - 1];
            prefixHasEvenXor[i + 1] = prefixHasEvenXor[i] + ((k & 1) == 0);
        }

        // Process each query
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            // Check if there's any even XOR in the range [l + 1, r]
            if (prefixHasEvenXor[r + 1] - prefixHasEvenXor[l + 1] > 0) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }

        return ans;
    }
};
