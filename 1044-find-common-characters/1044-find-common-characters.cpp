class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ff(26, INT_MAX);  // stores min frequency for each char

        for (const string& w : words) {
            vector<int> f(26, 0);
            for (char c : w) {
                f[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                ff[i] = min(ff[i], f[i]);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int count = 0; count < ff[i]; count++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};
