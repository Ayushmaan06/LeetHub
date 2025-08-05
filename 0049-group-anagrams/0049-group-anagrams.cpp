class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string& s : strs){
            string r=s;
            sort(s.begin(),s.end());
            mp[s].push_back(r);
        }
        vector<vector<string>> res;
        for(auto& it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};