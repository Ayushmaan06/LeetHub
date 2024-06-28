class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre,vector<int> &ans) {
        vector<int> ind(n,0);
        
        vector<vector<int>> graph(n);
        for (const auto& p : pre) {
            graph[p[1]].push_back(p[0]);
        }
        for(int i = 0 ; i < pre.size() ; i++){
            ind[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            ans.push_back(k); // Add to result
            // Decrease in-degree of adjacent vertices
            for (int i = 0; i < graph[k].size(); i++) {
                ind[graph[k][i]]--;
                if (ind[graph[k][i]] == 0) {
                    q.push(graph[k][i]);
                }
            }
        }
        return ans.size()==n;

    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        if(canFinish(n,pre,ans)){
            return ans;
        }
        ans.clear();
        return ans;
    }
};