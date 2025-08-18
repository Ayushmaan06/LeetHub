class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        if(n==1)return true;
        for(vector<int> e : edges){
            int u = e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(source);
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int i : adj[u]){
                if(i==destination)return true;
                if(!vis[i]){
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};