class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> sc(26, -1), st(26, -1);
        int i = 0;
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                sc[c - 'a'] = i;
            } else if (c >= 'A' && c <= 'Z') {
                if (st[c - 'A'] == -1) st[c - 'A'] = i;
            }
            i++;
        }

        int ans = 0;
        for (int ii = 0; ii < 26; ii++) {
            if (sc[ii] != -1 && sc[ii] < st[ii]) ans++;
        }
        return ans;
    }
};
