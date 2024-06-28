class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
    int V=adj.size();
    vector<int> color(V, -1); // Use a color array to store colors of vertices, initialized to -1 (uncolored)
    queue<int> q; // Queue for BFS

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // If the vertex is not colored
            q.push(i);
            color[i] = 1; // Color the vertex with color 1

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) { // If the neighbor is not colored
                        color[neighbor] = 1 - color[node]; // Color it with opposite color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) { // If the neighbor is colored with the same color
                        return false; // The graph is not bipartite
                    }
                }
            }
        }
    }

    return true; // If all vertices are colored such that no two adjacent vertices have the same color, the graph is bipartite
}
};