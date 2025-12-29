class TimeMap {
public:
    // Store pairs as {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
    }
    
    void set(string key, string value, int t) {
        mp[key].push_back({t, value});
    }
    
    string get(string key, int t) {
        if (mp.find(key) == mp.end()) return "";
        vector<pair<int,string>>& v = mp[key];
        int n = v.size(), l = 0, h = n - 1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if (v[m].first > t)h = m - 1;
            else l = m + 1;
        }
        if (h >= 0) return v[h].second;
        return "";
    }
};