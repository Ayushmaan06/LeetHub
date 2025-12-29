class Solution {
    unordered_set<string> invalid; 
public:
    bool solve(string& cur, unordered_map<string, vector<char>>& mp, string next, int ci) {
        if (cur.length() == 1) return true;
        if (next.length() == cur.length() - 1) {
            if (invalid.count(next)) return false;
            if (solve(next, mp, "", 0)) return true;
            invalid.insert(next);
            return false;
        }
        string key = cur.substr(ci, 2);
        if (mp.count(key)) {
            for (char x : mp[key]) {
                if (solve(cur, mp, next + x, ci + 1)) return true;
            }
        }
        return false;
    }

    bool pyramidTransition(string b, vector<string>& a) {
        unordered_map<string, vector<char>> mp;
        for (string s : a) mp[s.substr(0, 2)].push_back(s[2]);
        return solve(b, mp, "", 0);
    }
};