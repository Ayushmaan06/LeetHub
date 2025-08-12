class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1)return {0};
         vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses,0);
        for(auto & edge : prerequisites){
            int u = edge[0], v = edge[1];
            adj[v].push_back(u);
            ind[u]++;
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            if(ind[i]==0)q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int n = q.front();q.pop();
            res.push_back(n);
            for(int nn : adj[n]){
                ind[nn]--;
                if(ind[nn]==0)q.push(nn);
            }
        }
        if(res.size()!=numCourses)return {};
        return res;
    }
};