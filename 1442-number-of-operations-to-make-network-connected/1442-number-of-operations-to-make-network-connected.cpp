
class DSU {
private:
    vector<int> parent;
    vector<int> rank;  
public:
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }
    bool unionSets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        DSU dsu(n);
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            dsu.unionSets(u, v);
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i)
                components++;
        }
        return components - 1;
    }
};
