class Solution {
public:
    string mask(string s) {
        for (char& c : s) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wl, vector<string>& q) {
        unordered_set<string> st(wl.begin(), wl.end());
        unordered_map<string, string> lowMap;
        unordered_map<string, string> vowMap;
        for (string w : wl) {
            string low = w;
            transform(low.begin(), low.end(), low.begin(), ::tolower);
            if (lowMap.find(low) == lowMap.end())
                lowMap[low] = w;
            string mv = mask(w);
            if (vowMap.find(mv) == vowMap.end())
                vowMap[mv] = w;
        }
        vector<string> ans;
        for (string x : q) {
            if (st.count(x)) {
                ans.push_back(x);
                continue;
            }
            string l = x;
            transform(l.begin(), l.end(), l.begin(), ::tolower);
            if (lowMap.count(l)) {
                ans.push_back(lowMap[l]);
                continue;
            }
            string m = mask(x);
            if (vowMap.count(m)) {
                ans.push_back(vowMap[m]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
