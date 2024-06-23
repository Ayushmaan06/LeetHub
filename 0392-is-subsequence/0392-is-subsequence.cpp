class Solution {
public:
    bool isSubsequence(string s, string t) {
        int indexS = 0, indexT = 0; // Pointers for s and t
        while (indexS < s.size() && indexT < t.size()) {
            if (s[indexS] == t[indexT]) {
                indexS++; // Move to the next character in s
            }
            indexT++; // Always move to the next character in t
        }
        return indexS == s.size(); // Check if we've found all characters of s in t
    }
};