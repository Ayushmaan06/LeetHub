class Solution {
public:
    bool isPal(const string& str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }

    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s; // Use '#' as a separator

        // Compute LPS array
        vector<int> lps(combined.size(), 0);
        for (int i = 1; i < combined.size(); ++i) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) ++len;
            lps[i] = len;
        }

        // Use LPS to find the longest palindrome prefix
        return rev_s.substr(0, s.size() - lps.back()) + s;
    }
};