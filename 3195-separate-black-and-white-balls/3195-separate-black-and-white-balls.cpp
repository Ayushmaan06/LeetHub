class Solution {
public:
    long long minimumSteps(string s) {
        long long white = 0;  
        long long res = 0;    
        long long n = s.length();
        
        for (long long j = 0; j < n; ++j) {
            if (s[j] == '0') {
                res += white;  // Add the number of '1's seen so far to the result
            } else if (s[j] == '1') {
                white++;  
            }
        }
        
        return res;
    }
};