#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> allPairShortestPath(const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else if (adj[i][j] != 0) {
                    dist[i][j] = adj[i][j];
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) { 
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        return dist;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (vector<int>& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            mat[u][v] = w;
            mat[v][u] = w;
        }
        vector<vector<int>> dist = allPairShortestPath(mat);
        int ans = -1, countMin = INF;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= k) {
                    cnt++;
                }
            }
            if (cnt <= countMin) {
                countMin = cnt;
                ans = i;
            }
        }
        return ans;
    }
};