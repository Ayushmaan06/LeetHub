class Solution {
public:
    vector<long long> dijkstra( int src, vector<vector<pair<int, int>>> &adj) {
        int n=26;
        vector<long long> dist(n, 1e9);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d != dist[u]) continue;

            for (auto &edge : adj[u]) {
                int v = edge.second;
                int weight = edge.first;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> map(26); // Initialize map for 26 letters
        vector<vector<int>> m(26);
        // Populate the map with transformation costs
        for (int i = 0; i < original.size(); i++) {
            map[original[i] - 'a'].push_back({cost[i], changed[i] - 'a'});
        }
        for (int i = 0; i < source.size(); i++) {
            m[source[i] - 'a'].push_back(target[i]-'a');
        }
        long long c = 0;
        for(int i = 0 ; i < m.size(); i++ ){
            if(m[i].size()>0){
               vector<long long>d = dijkstra(i,map);
               for(int j = 0 ; j < m[i].size() ; j++){
                    if(d[m[i][j]]==1e9){
                        return -1;
                    }
                    else{
                        c+=d[m[i][j]];
                    }
               }
            }
        }
        return c;
    }
};