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
    vector<int> findAllPeople(int n, vector<vector<int>>& vec, int fp) {
    //     sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
    //     return a[2] < b[2];
    // });
        DSU dsu(n);
        dsu.unionByRank(0,fp);
        // for(vector<int> v : vec){
        //     int x = v[0], y = v[1];
        //     if(dsu.find(x)==dsu.find(0) || dsu.find(y)==dsu.find(0))dsu.unionByRank(x,y);
        // }
        vector<int> res;
        map<int,vector<pair<int,int>>>mp;
        for(vector<int> v : vec){
            mp[v[2]].push_back({v[0],v[1]});
        }
        for(auto& it : mp){
            vector<pair<int,int>> vp = it.second;
            vector<int> p;
            for(auto[x,y] : vp){dsu.unionByRank(x,y);p.push_back(x);p.push_back(y);}
            for(int pp : p)if(dsu.find(pp)!=dsu.find(0))dsu.reset(pp);
        }
        for(int i = 0 ; i < n ; i++){
            if(dsu.find(0)==dsu.find(i))res.push_back(i);
        }
        return res;
    }
};