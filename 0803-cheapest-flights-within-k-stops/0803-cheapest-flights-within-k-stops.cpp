class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> p(n,INT_MAX);
        p[src]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(vector<int>& f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        queue<vector<int>> q;
        q.push({0,0,src});
        while(!q.empty()){
            vector<int> t = q.front();
            q.pop();
            int c = t[0], st=t[1], u=t[2];
            if(st>k)continue;
            for(auto[v,d] : adj[u]){
                if(d+c<p[v]){
                    p[v]=d+c;
                    q.push({p[v],st+1,v});
                }
            }
        }
        if(p[dst]==INT_MAX)return -1;
        return p[dst];
    }
};