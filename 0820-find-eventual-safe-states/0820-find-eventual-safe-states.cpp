
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rg(n); // Reverse graph
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                rg[graph[i][j]].push_back(i); // Reverse the edge
            }
        }
        vector<int> ind(n, 0); // In-degree
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < rg[i].size(); j++) {
                ind[rg[i][j]]++; // Calculate in-degree
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(ind[i] == 0) q.push(i); // Nodes with 0 in-degree
        }
        vector<int> v;
        while(!q.empty()) {
            int k = q.front();
            v.push_back(k);
            q.pop();
            for(int i = 0; i < rg[k].size(); i++) {
                ind[rg[k][i]]--;
                if(ind[rg[k][i]] == 0) q.push(rg[k][i]); // Decrease in-degree and check
            }
        }
        sort(v.begin(), v.end()); // Sort the result
        return v;
    }
};