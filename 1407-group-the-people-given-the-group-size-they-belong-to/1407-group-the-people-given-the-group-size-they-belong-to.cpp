class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,queue<int>> mp;
        int n = g.size();
        for(int i=0;i<n;i++){
            mp[g[i]].push(i);
        }
        vector<vector<int>> res;
        for(auto it : mp){
            int i = it.first;queue<int> v=it.second;
            while(v.size()){
                vector<int> t;
                for(int j = 0 ; j < i ; j++){
                    t.push_back(v.front());
                    v.pop();
                }
                res.push_back(t);
            }
        }
        return res;
    }
};