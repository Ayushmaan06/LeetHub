#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
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
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DSU dsu(n * m);
        
        // Perform union for all adjacent cells that are '1'
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == '1'){
                    for (auto [r, c] : dir) {
                        int rr = i + r, cc = j + c;
                        if (rr >= 0 && cc >= 0 && rr < n && cc < m && grid[rr][cc] == '1'){
                            int idx = i * m + j;
                            int nidx = rr * m + cc;
                            dsu.unionBySize(idx, nidx);
                        }
                    }
                }
            }
        }
        unordered_set<int> islands;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    islands.insert(dsu.find(i * m + j));
                }
            }
        }
        return islands.size();
    }
};