class Solution {
public:
    string reorganizeString(string s) {
        string res;
        unordered_map<char,int> mp;
        for(char c : s) mp[c]++;

        priority_queue<pair<int,char>> pq;
        for(auto it : mp) pq.push({it.second, it.first});

        while(pq.size() > 1) {
            auto [ac, a] = pq.top(); pq.pop();
            auto [bc, b] = pq.top(); pq.pop();

            res += a;
            res += b;

            if(--ac > 0) pq.push({ac, a});
            if(--bc > 0) pq.push({bc, b});
        }

        if(!pq.empty()) {
            if(pq.top().first > 1) return "";
            if(!res.empty() && res.back() == pq.top().second) return "";
            res += pq.top().second;
        }

        return res;
    }
};
