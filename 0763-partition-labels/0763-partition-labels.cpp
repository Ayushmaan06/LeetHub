class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;unordered_set<char> ss;vector<int>res;
        int l = 0 , r= 0;
        for(char c : s)mp[c]++;
        while(r<s.length()){
            char c = s[r];
            ss.insert(c);
            mp[c]--;
            if(mp[c]==0)ss.erase(c);
            if(ss.empty())res.push_back(r-l+1),l=r+1;
            r++;
        }
        return res;
    }
};
