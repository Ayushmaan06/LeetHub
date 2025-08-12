class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses <=0)return true;
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
        int p =0;
        while(!q.empty()){
            int n = q.front();q.pop();p++;
            for(int nei : adj[n]){
                if(--ind[nei]==0)q.push(nei);
            }
        }
        return p == numCourses;
    }
};