class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        // sort(bulbs.begin(),bulbs.end());
        unordered_map<int,int> m;
        for(int b : bulbs)m[b]++;
        set<int> res;
        for(int b : bulbs)if(m[b]%2)res.insert(b);
        vector<int> r (res.begin(),res.end());
        return r;
    }
};