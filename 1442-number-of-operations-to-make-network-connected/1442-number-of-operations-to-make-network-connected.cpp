class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        // Build the graph
        for (const auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        int numComponents = 0;
        
        // Perform BFS for each component
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                numComponents++;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int neighbor : graph[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        
        // To connect all components, we need (numComponents - 1) extra edges
        return numComponents - 1;
    }
};
