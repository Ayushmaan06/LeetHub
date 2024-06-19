class Solution {
public:
    vector<int> computeKMPTable(const string& W) {
        int n = W.size();
        vector<int> T(n + 1, 0);
        T[0] = -1;
        int i = 0, j = -1;
        while (i < n) {
            while (j >= 0 && W[i] != W[j]) {
                j = T[j];
            }
            i++;
            j++;
            T[i] = j;
        }
        return T;
    }

    vector<int> KMP(const string& S, const string& W) {
        vector<int> T = computeKMPTable(W);
        vector<int> matches;
        int m = 0, i = 0;
        while (m + i < S.size()) {
            if (W[i] == S[m + i]) {
                if (i == W.size() - 1) {
                    matches.push_back(m);
                    m = m + i - T[i];
                    i = (T[i] > -1) ? T[i] : 0;
                } else {
                    i++;
                }
            } else {
                if (T[i] > -1) {
                    m = m + i - T[i];
                    i = T[i];
                } else {
                    i = 0;
                    m++;
                }
            }
        }
        return matches;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // Base case: empty string

        for (int i = 1; i <= n; ++i) {
            for (const string& word : wordDict) {
                int len = word.length();
                if (i >= len && dp[i - len]) {
                    string substring = s.substr(i - len, len);
                    if (substring == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};
