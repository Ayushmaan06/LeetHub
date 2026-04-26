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
    void reset(int a){parent[a]=a;}
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DSU dsu(n * m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int id = i * m + j;
                if(j + 1 < m && grid[i][j] == grid[i][j+1]) {
                    int nid = i * m + (j + 1);
                    if(dsu.find(id) == dsu.find(nid)) return true;
                    dsu.unionByRank(id, nid);
                }
                if(i + 1 < n && grid[i][j] == grid[i+1][j]) {
                    int nid = (i + 1) * m + j;
                    if(dsu.find(id) == dsu.find(nid)) return true;
                    dsu.unionByRank(id, nid);
                }
            }
        }
        return false;
    }
};