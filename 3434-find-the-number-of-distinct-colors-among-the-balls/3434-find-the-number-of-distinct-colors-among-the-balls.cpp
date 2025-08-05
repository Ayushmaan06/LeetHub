class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        // vector<int> vis(limit+1,-1);
        unordered_map<int,int> col;
        vector<int> res;
        for(vector<int>& q : queries){
            // if(vis[q[0]]>-1){
            //     mp[vis[q[0]]]--;
            //     if (mp[vis[q[0]]]==0)
            //         mp.erase(vis[q[0]]);
            //     mp[q[1]]++;
            //     vis[q[0]]=q[1];
            // }
            if(col.find(q[0])!=col.end()){
                mp[col[q[0]]]--;
                if (mp[col[q[0]]]==0)
                    mp.erase(col[q[0]]);
                mp[q[1]]++;
                col[q[0]]=q[1];
            }
            else{
                col[q[0]]=q[1];
                mp[q[1]]++;

            }

            
            res.push_back(mp.size());
        }
        return res;
    }
};