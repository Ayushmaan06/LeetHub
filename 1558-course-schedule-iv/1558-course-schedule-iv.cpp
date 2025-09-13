class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(vector<int> p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        vector<vector<bool>> isr(n,vector<bool>(n,false));
        for(int i = 0 ; i < n ; i++){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int src = q.front();q.pop();
                for(int v : adj[src]){
                    // isr[src][v]=true;
                    if(!isr[i][v]){
                        isr[i][v]=true;
                        q.push(v);
                    }
                }
            }
        }
        vector<bool> res;
        for(vector<int> q : queries){
            res.push_back(isr[q[0]][q[1]]);
        }
        return res;
    }
};