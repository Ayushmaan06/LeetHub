class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order) {
        if (visited[node] == 1) return false; // cycle detected
        if (visited[node] == 2) return true; // already visited

        visited[node] = 1;
        for (int next : adj[node]) {
            if (!dfs(next, adj, visited, order)) return false;
        }
        visited[node] = 2;
        order.push_back(node);
        return true;
    }

    vector<int> topoSort(int k, vector<vector<int>>& constraints) {
        vector<vector<int>> adj(k);
        for (auto& c : constraints) {
            adj[c[0] - 1].push_back(c[1] - 1); // Adjusting for 0-based indexing
        }

        vector<int> order;
        vector<int> visited(k, 0);

        for (int i = 0; i < k; ++i) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, order)) return {}; // cycle detected, return empty vector
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConstraints, vector<vector<int>>& colConstraints) {
        vector<vector<int>> mat(k, vector<int>(k, 0));
        
        vector<int> rowOrder = topoSort(k, rowConstraints);
        vector<int> colOrder = topoSort(k, colConstraints);

        if (rowOrder.empty() || colOrder.empty()) return {}; // cycle detected, return empty matrix

        vector<int> rowPosition(k), colPosition(k);
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }

        for (int i = 0; i < k; ++i) {
            mat[rowPosition[i]][colPosition[i]] = i + 1; // Adjusting for 1-based values
        }

        return mat;
    }
};
