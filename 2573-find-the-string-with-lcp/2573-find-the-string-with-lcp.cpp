class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, ' ');
        char c = 'a';

        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') continue;
            if (c > 'z') return "";
            
            s[i] = c;
            for (int j = i + 1; j < n; ++j) {
                if (lcp[i][j] > 0) s[j] = c;
            }
            c++;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int e = 0;
                if (s[i] == s[j]) {
                    e = (i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] + 1 : 1;
                }
                
                if (lcp[i][j] != e) return "";
            }
        }

        return s;
    }
};