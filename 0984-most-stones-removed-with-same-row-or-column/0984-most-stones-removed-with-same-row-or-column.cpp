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
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mr=0,mc=0,n=stones.size();
        for(vector<int> &v : stones){
            mr=max(mr,v[0]);
            mc=max(mc,v[1]);
        }
        DSU dsu(mr+mc+2);
        unordered_set<int> s;
        for(vector<int> &v : stones){
            dsu.unionByRank(v[0],mr+v[1]+1);
            s.insert(v[0]);
            s.insert(v[1]+mr+1);
        }
        int ans=0;
        for(auto& it : s){
            int x = it;
            if(dsu.find(x)==x)ans++;
        }
        return (n-ans);
    }
};