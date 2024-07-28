class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        auto calculateWaitTime = [&](int t) {
            int cycle = change * 2;
            if ((t / change) % 2 == 1) {
                return cycle - (t % cycle);
            }
            return 0;
        };

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({1, 0});
        dist1[1] = 0;

        while (!q.empty()) {
            auto [node, t] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                int waitTime = calculateWaitTime(t);
                int newTime = t + time + waitTime;

                if (newTime < dist1[neighbor]) {
                    dist2[neighbor] = dist1[neighbor];
                    dist1[neighbor] = newTime;
                    q.push({neighbor, newTime});
                } else if (newTime > dist1[neighbor] && newTime < dist2[neighbor]) {
                    dist2[neighbor] = newTime;
                    q.push({neighbor, newTime});
                }
            }
        }

        return dist2[n];
    }
};