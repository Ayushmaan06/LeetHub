#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;  // For union by rank
    vector<int> size;  // For union by size

public:
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
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
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

    int getSize(int a) {
        return size[find(a)];
    }
    void reset(int a) { parent[a] = a; }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c + 1);
        for (auto& conn : connections)
            dsu.unionBySize(conn[0], conn[1]);
        vector<int> res;
        unordered_map<int, set<int>> mp;  
        for (int i = 1; i <= c; i++)
            mp[dsu.find(i)].insert(i);
        unordered_set<int> off;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            if (x == 2) {
                off.insert(y);
                mp[dsu.find(y)].erase(y); 
            } else {
                int root = dsu.find(y);
                if(off.count(y)){
                    if (mp[root].empty()) {
                        res.push_back(-1);
                    } else {
                        res.push_back(*mp[root].begin());
                    }
                }
                else res.push_back(y);
            }
        }
        return res;
    }
};
