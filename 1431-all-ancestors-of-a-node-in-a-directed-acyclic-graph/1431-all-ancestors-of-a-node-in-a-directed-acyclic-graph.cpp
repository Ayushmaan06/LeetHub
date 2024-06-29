class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Step 1: Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Prepare the result container and a visited set for each node
        vector<set<int>> ancestors(n);

        // Helper function for DFS
        function<void(int)> dfs = [&](int node) {
            for (int parent : adj[node]) {
                if (ancestors[node].insert(parent).second) {  // If parent was not already an ancestor
                    dfs(parent);  // Visit parent's ancestors
                    ancestors[node].insert(ancestors[parent].begin(), ancestors[parent].end());
                }
            }
        };

        // Step 3: Perform DFS for each node to collect all ancestors
        for (int i = 0; i < n; ++i) {
            dfs(i);
        }

        // Step 4: Convert the result from set to vector
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i].assign(ancestors[i].begin(), ancestors[i].end());
        }

        return result;
    }
};
