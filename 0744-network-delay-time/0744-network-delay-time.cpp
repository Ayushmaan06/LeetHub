class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            // Adjust for 1-indexed node numbering
            graph[time[0]].emplace_back(time[1], time[2]);
        }

        // Use greater<> to make it a min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [dis, src] = pq.top();
            pq.pop();
            if (dis > dist[src]) continue; // Check for outdated distance

            for (auto [dst, p] : graph[src]) {
                if (dist[dst] > dis + p) {
                    dist[dst] = dis + p;
                    pq.push({dist[dst], dst});
                }
            }
        }

        int maxTime = *max_element(dist.begin() + 1, dist.end()); // Skip index 0
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};