class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> mp;
        int ma = INT_MIN;
        for (char c : s) {
            mp[c]++;
            ma = max(ma, mp[c]);
        }
        for (auto it = mp.begin(); it != mp.end(); ) {
            it->second -= ma;
            it->second++;
            if (it->second <= 0)
                it = mp.erase(it);
            else
                ++it;
        }
        int n = s.length();
        string res = "";
        for (int i = n - 1; i >= 0; i--) {
            if (mp[s[i]] > 0) {
                mp[s[i]]--;
                res += s[i];
                if (mp[s[i]] <= 0)
                    mp.erase(s[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
