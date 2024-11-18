class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        if (k == 0) {
            return ans; 
        }

        int start = k > 0 ? 1 : n + k; // Start of the range
        int end = k > 0 ? k : n - 1;   // End of the range
        k = abs(k); // Use positive value of k for simplicity
        
        int windowSum = 0;
        for (int i = start; i <= end; i++) {
            windowSum += code[i % n];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = windowSum;
            windowSum -= code[(start++) % n];
            windowSum += code[(++end) % n];
        }

        return ans;
    }
};
