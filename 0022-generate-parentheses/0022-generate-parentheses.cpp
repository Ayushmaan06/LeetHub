class Solution {
public:
    void solve(string o, int ob, int cb, int n, vector<string>& r) {
        if(ob == n && cb == n) { 
            r.push_back(o);
            return;
        }
        if(ob < n) solve(o + '(', ob + 1, cb, n, r);
        if(cb < ob) solve(o + ')', ob, cb + 1, n, r);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> r;
        solve("", 0, 0, n, r);
        return r;
    }
};
