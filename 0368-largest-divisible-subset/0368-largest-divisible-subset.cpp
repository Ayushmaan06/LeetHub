class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // 1. Sort is mandatory

        // DP Table
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // 2. Fill the Table (Your original logic)
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                
                // Option 1: Skip (Not Take)
                int len = dp[ind + 1][prev_ind + 1]; 

                // Option 2: Take (if valid)
                if (prev_ind == -1 || arr[ind] % arr[prev_ind] == 0) {
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }
                
                dp[ind][prev_ind + 1] = len;
            }
        }

        // 3. Path Reconstruction (The "Hash Array" equivalent for 2D)
        // We walk through the table to see which elements were picked.
        vector<int> result;
        int prev_ind = -1; 
        
        for (int ind = 0; ind < n; ind++) {
            // "Current State" value in DP: dp[ind][prev_ind + 1]
            // "Skip State" value in DP:    dp[ind + 1][prev_ind + 1]
            
            // If the value is the same, it means we SKIPPED this element (Not Take)
            if (dp[ind][prev_ind + 1] == dp[ind + 1][prev_ind + 1]) {
                continue; 
            } else {
                // If the value is different (larger), it means we TOOK this element
                result.push_back(arr[ind]);
                prev_ind = ind; // Update prev_ind for the next check
            }
        }
        
        return result;
    }
};