class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i  = 0 ; i < graph.size() ; i++){
            for(int g : graph[i]){
                adj[g].push_back(i);
                ind[i]++;
            }   
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(ind[i]==0)q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int nn = q.front();q.pop();
            res.push_back(nn);
            for(int nnn : adj[nn]){
                ind[nnn]--;
                if(ind[nnn]==0)q.push(nnn);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};