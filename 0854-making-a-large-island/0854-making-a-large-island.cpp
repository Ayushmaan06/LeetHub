class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }

    int getSize(int u) {
        return size[find(u)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int maxIsland = 0, currentIslandSize;
        bool hasWater = false;

        // Mark and union existing land
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int index = i * n + j;
                    grid[i][j] = 2; // Mark as visited
                    for (auto& dir : directions) {
                        int nr = i + dir.first, nc = j + dir.second;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 2) {
                            ds.unite(index, nr * n + nc);
                        }
                    }
                } else if (grid[i][j] == 0) {
                    hasWater = true;
                }
            }
        }

        // If no water is found, the entire grid is an island
        if (!hasWater) return n * n;

        // Calculate the largest island if a water cell is converted to land
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> adjacentIslands;
                    currentIslandSize = 1; // Start with the current cell being converted to land
                    for (auto& dir : directions) {
                        int nr = i + dir.first, nc = j + dir.second;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 2) {
                            int root = ds.find(nr * n + nc);
                            if (adjacentIslands.insert(root).second) { // If insertion is successful (unique island)
                                currentIslandSize += ds.getSize(root);
                            }
                        }
                    }
                    maxIsland = max(maxIsland, currentIslandSize);
                }
            }
        }

        return maxIsland;
    }
};