class Solution {
public:
    void solve(vector<string>& ss, int n, string& s) {
        if (s.size() == n) {
            ss.push_back(s);
            return;
        }
        s.push_back('1');
        solve(ss, n, s);
        s.pop_back();
        if (s.empty() || s.back() != '0') {
            s.push_back('0');
            solve(ss, n, s);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ss;
        string s = "";
        solve(ss, n, s);
        return ss;
    }
};
