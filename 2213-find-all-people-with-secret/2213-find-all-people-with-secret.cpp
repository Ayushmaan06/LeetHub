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
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DSU dsu(n);
        dsu.unionByRank(0, firstPerson);
        map<int, vector<pair<int,int>>> mp;
        for(auto &v : meetings) {
            mp[v[2]].push_back({v[0], v[1]});
        }
        for(auto &entry : mp){
            int time = entry.first;
            vector<pair<int,int>> vp = entry.second;
            unordered_set<int> groupSet;
            for(auto [x, y] : vp){
                groupSet.insert(x);
                groupSet.insert(y);
            }
            vector<int> group(groupSet.begin(), groupSet.end());
            unordered_map<int, vector<int>> graph;
            for(auto [x,y] : vp){
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
            unordered_set<int> visited;
            for(auto p : group){
                if(visited.count(p)) continue;
                vector<int> comp;
                bool hasSecret = false;
                queue<int> qu;
                qu.push(p);
                visited.insert(p);
                while(!qu.empty()){
                    int cur = qu.front();
                    qu.pop();
                    comp.push_back(cur);
                    if(dsu.find(cur) == dsu.find(0))
                        hasSecret = true;
                    for(auto nxt : graph[cur]){
                        if(!visited.count(nxt)){
                            visited.insert(nxt);
                            qu.push(nxt);
                        }
                    }
                }
                if(hasSecret){
                    for(auto member : comp){
                        dsu.unionByRank(member, 0);
                    }
                }
            }
        }
        vector<int> res;
        for(int i = 0 ; i < n ; i++){
            if(dsu.find(i) == dsu.find(0))
                res.push_back(i);
        }
        return res;
    }
};