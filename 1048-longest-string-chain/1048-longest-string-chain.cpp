class Solution {
public:
    // Optimization: Pass strings by reference to avoid copying
    bool solve(const string& a, const string& b) {
        if (a.length() != b.length() + 1) {
            return false;
        }
        int i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                i++;
                // Check if the rest of the strings match
                if (a.substr(i) == b.substr(j)) {
                    return true;
                }
                return false;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        
        // CHANGE: Sort by Length instead of Alphabetical order
        sort(arr.begin(), arr.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = dp[ind + 1][prev_ind + 1]; 
                if (prev_ind == -1 || solve(arr[ind], arr[prev_ind])) {
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }
                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][0];
    }
};