#define ll long long
class Solution {
public:
    
    int minCost(int n, vector<vector<int>>& edges) {
        const long long INF =1e18;
        ll o=1,t=2,z=0;
        vector<vector<pair<int,int>>> adj(n),rev(n);
        for(auto& e : edges){
            int u = e[z],v=e[o],w=e[t];
            adj[u].push_back({v,w});
            rev[v].push_back({u,w});
        }
        vector<ll>d(n,INF);
        vector<bool> ur(n,false);
        using State = pair<long long, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        d[z]=z;pq.push({z,z});
        while(!pq.empty()){
            auto[di,u]=pq.top();
            pq.pop();
            if(di!=d[u])continue;
            for(auto &e : adj[u]){
                int v=e.first,w=e.second;
                if(di+w<d[v]){
                    d[v]=di+w;pq.push({d[v],v});
                }
            }
            if(!ur[u]){
                ur[u]=true;
                for(auto& e : rev[u]){
                    int v = e.first,w=e.second;
                    if(di+t*w<d[v]){
                        d[v]=di+t*w;
                        pq.push({d[v],v});
                    }
                }
            }
        }
        return (d[n - 1] == INF ? -1 : static_cast<int>(d[n - 1]));
    }
};