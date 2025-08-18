#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> c(n, -1);
        // Process all connected components.
        for (int i = 0; i < n; i++) {
            if (c[i] == -1) {
                c[i] = 0;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : graph[u]) {
                        if (c[v] == c[u])
                            return false;
                        if (c[v] == -1) {
                            c[v] = c[u] ^ 1;
                            q.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }
};