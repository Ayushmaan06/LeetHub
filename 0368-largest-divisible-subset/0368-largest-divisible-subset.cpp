class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); 
        vector<int> dp(n, 1);     // dp[i] = max length ending at i
        vector<int> hash(n);      // hash[i] = index of previous element
        int maxi = 1;             // Length of the longest subset found
        int lastIndex = 0;        // The ending index of that subset
        for(int i=0; i<n; i++) hash[i] = i;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; 
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        return temp;
    }
};