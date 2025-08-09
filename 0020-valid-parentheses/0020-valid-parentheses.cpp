class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> m = {
            {'(', -1},
            {'{', -2},
            {'[', -3},
            {')', +1},
            {'}', +2},
            {']', +3}
        };
        stack<char> a;

        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] < 0) {
                a.push(s[i]);
            } else if (m[s[i]] > 0 && a.empty()) {
                return false;
            } else if (m[s[i]] > 0 && m[s[i]] + m[a.top()] != 0) {
                return false;
            } else if (m[s[i]] > 0 && m[s[i]] + m[a.top()] == 0) {
                a.pop();
            }
        }

        return a.empty();
    }
};