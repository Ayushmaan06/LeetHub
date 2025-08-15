#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;  // For union by rank
    vector<int> size;  // For union by size

public:
    // Constructor: initialize DSU with n elements (0-indexed)
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Path compression find
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    // Union by rank: attach tree with lower rank under tree with higher rank
    void unionByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }

    // Union by size: attach tree with smaller size under tree with larger size
    void unionBySize(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

    int getSize(int a) {
        return size[find(a)];
    }
};

class Solution {
    // 4-directional moves: up, right, down, left.
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DSU dsu(n * m);
        
        // Build DSU only over land cells.
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) {
                    int idx = i * m + j;
                    for (auto [dr, dc] : dir) {
                        int rr = i + dr, cc = j + dc;
                        if (rr >= 0 && rr < n && cc >= 0 && cc < m && grid[rr][cc] == 1) {
                            int nidx = rr * m + cc;
                            dsu.unionBySize(idx, nidx);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        bool foundZero = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0) {
                    foundZero = true;
                    unordered_set<int> comps;
                    for (auto [dr, dc] : dir) {
                        int rr = i + dr, cc = j + dc;
                        if (rr >= 0 && rr < n && cc >= 0 && cc < m && grid[rr][cc] == 1) {
                            comps.insert(dsu.find(rr * m + cc));
                        }
                    }
                    int total = 0;
                    for (auto comp : comps) {
                        total += dsu.getSize(comp);
                    }
                    ans = max(ans, total + 1);
                }
            }
        }
        if (!foundZero) return n * m;
        return ans;
    }
};
