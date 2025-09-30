class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    void unionBySize(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(),z=0;
        DSU dsu(n * m);
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    for (auto [dx, dy] : dir) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '1') {
                            dsu.unionBySize(i * m + j, ni * m + nj);
                        }
                    }
                }
                else z++;
            }
        }
        // unordered_set<int> uniqueIslands;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (grid[i][j] == '1') {
        //             uniqueIslands.insert(dsu.find(i * m + j));
        //         }
        //     }
        // }
        int ans=0;
        for(int i = 0 ; i < m*n ; i++)if(dsu.find(i)==i)ans++;
        return ans-z;
    }
};
