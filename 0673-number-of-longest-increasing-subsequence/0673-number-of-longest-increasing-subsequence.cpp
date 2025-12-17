class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        
        vector<int> dp(n, 1);  // Length of LIS ending at i
        vector<int> count(n, 1); // Number of LIS ending at i
        
        int maxi = 1; // Store the global maximum length found so far

        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(arr[prev] < arr[i]) {
                    // Case 1: Found a longer subsequence
                    if(dp[prev] + 1 > dp[i]) {
                        dp[i] = dp[prev] + 1;
                        // Inherit count from prev because this is a new strictly longer path
                        count[i] = count[prev]; 
                    }
                    // Case 2: Found another subsequence of the SAME length
                    else if(dp[prev] + 1 == dp[i]) {
                        // Add the counts from prev to the current count
                        count[i] += count[prev]; 
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int numberOfLIS = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi) {
                numberOfLIS += count[i];
            }
        }
        
        return numberOfLIS;
    }
};