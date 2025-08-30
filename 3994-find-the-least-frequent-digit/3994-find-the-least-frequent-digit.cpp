#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        int ans = s[0];
        int minFreq = s.length();
        int i = 0;

        while (i < s.length()) {
            int j = i;
            while (j < s.length() && s[j] == s[i]) {
                j++;
            }
            int freq = j - i;
            if (freq < minFreq) {
                minFreq = freq;
                ans = s[i];
            }
            i = j;
        }

        return ans - '0'; 
    }
};
