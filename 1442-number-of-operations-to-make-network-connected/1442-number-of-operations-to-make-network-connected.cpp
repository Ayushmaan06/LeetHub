class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        if (e < n - 1) return -1; 
        vector<vector<int>> adj(n);
        for (auto& c : connections) {
            int u = c[0], v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cc = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            cc++;
            queue<int> q;
            q.push(i);
            vis[i] = true; 
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true; 
                        q.push(v);
                    }
                }
            }
        }
        return cc - 1;
    }
};
