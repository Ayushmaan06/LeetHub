class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // Priority queue to store (cost, node, stops)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        dist[src] = 0;
        stops[src] = 0;
        pq.emplace(0, make_pair(src, 0));

        vector<int> memo(n);
        for (int i = 0; i < memo.size(); i++) {
            memo[i] = i;
        }

        while (!pq.empty()) {
            auto [d, node_stops] = pq.top();
            int node = node_stops.first;
            int current_stops = node_stops.second;
            pq.pop();

            if (node == dst) return d;
            if (current_stops > k) continue;

            for (const auto& [next_node, price] : graph[node]) {
                int new_cost = d + price;
                if (new_cost < dist[next_node] || current_stops + 1 < stops[next_node]) {
                    dist[next_node] = new_cost;
                    stops[next_node] = current_stops + 1;
                    pq.emplace(new_cost, make_pair(next_node, current_stops + 1));
                    memo[next_node] = node;
                }
            }
        }

        int i = dst, c = 0;
        while (memo[i] != i) {
            c++;
            i = memo[i];
        }

        if (c <= k && dist[dst] != INT_MAX) return dist[dst];
        return -1;
    }
};