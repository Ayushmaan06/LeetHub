class Solution {
public:
    int minimumPushes(string s) {
        vector<pair<int, char>> vp;
        unordered_map<char, int> m;
        for (char &c : s) {
            m[c]++;
        }
        if (m.size() <= 8) return s.length();

        for (auto k : m) {
            vp.push_back({k.second, k.first});
        }

        sort(vp.begin(), vp.end(), [](pair<int, char> a, pair<int, char> b) { return a.first > b.first; });

        int push = 0;
        for (int i = 0; i < vp.size(); i++) {
            if (i < 8) {
                push += vp[i].first;
            } else if (i >= 8 && i < 16) {
                push += 2 * vp[i].first;
            } 
            else if(i>=16 && i<24){
                push += 3 * vp[i].first;
            }
            else {
                push += 4 * vp[i].first;
            }
        }

        return push;
    }
};