class Solution {
public:
    int countPaths(int n, vector<vector<int>>& times) {
        const int mod = 1e9 + 7;
        
        // Create the adjacency list for the graph
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& time : times) {
            graph[time[0]].emplace_back(time[1], time[2]);
            graph[time[1]].emplace_back(time[0], time[2]);
        }

        // Priority queue to store the current shortest distance to each node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});

        // Distance and path count vectors
        vector<long long> dist(n, LLONG_MAX);
        vector<int> count(n, 0);
        dist[0] = 0;
        count[0] = 1;

        while (!pq.empty()) {
            auto [current_dist, u] = pq.top();
            pq.pop();

            if (current_dist > dist[u]) continue;

            for (auto& [v, weight] : graph[u]) {
                long long new_dist = current_dist + weight;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    count[v] = count[u];
                    pq.push({new_dist, v});
                } else if (new_dist == dist[v]) {
                    count[v] = (count[v] + count[u]) % mod;
                }
            }
        }

        return count[n - 1];
    }
};