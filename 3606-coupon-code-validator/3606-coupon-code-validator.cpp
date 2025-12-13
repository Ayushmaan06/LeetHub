class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& line, vector<bool>& active) {
        vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_map<string, int> pos;
        for (int i = 0; i < 4; i++) pos[order[i]] = i;

        vector<vector<string>> v(4);

        for (int i = 0; i < code.size(); i++) {
            if (!active[i]) continue;
            if (pos.find(line[i]) == pos.end()) continue;
            if (code[i].empty()) continue;

            bool ok = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            v[pos[line[i]]].push_back(code[i]);
        }

        vector<string> res;
        for (int i = 0; i < 4; i++) {
            sort(v[i].begin(), v[i].end());
            for (auto &s : v[i]) res.push_back(s);
        }

        return res;
    }
};
