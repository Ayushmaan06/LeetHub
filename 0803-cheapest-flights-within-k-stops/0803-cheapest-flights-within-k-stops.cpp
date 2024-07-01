class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& f : flights) {
            graph[f[0]].emplace_back(f[1], f[2]);
        }

        // Priority queue to store {cost, node, stops}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Use memo to track the number of stops to each node
        vector<int> memo(n, INT_MAX);
        memo[src] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            if (stops > K) continue;

            for (const auto& [next, price] : graph[node]) {
                // Only consider this path if it doesn't exceed the minimum distance or allows fewer stops
                if (cost + price < dist[next] || stops < memo[next]) {
                    dist[next] = cost + price;
                    pq.emplace(dist[next], next, stops + 1);
                    memo[next] = stops; // Update the number of stops to reach 'next'
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};