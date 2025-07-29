class Solution {
public:
     string maximumOddBinaryNumber(string s) {
        int ones = 0, zeros = 0;
        
        // Count the number of ones and zeros in the string
        for(char c : s) {
            if(c == '1') ones++;
            else zeros++;
        }
        
        // Print (n-1) ones, followed by m zeros, and finally, print the remaining one
        return string(ones - 1, '1') + string(zeros, '0') + '1';
    }
};