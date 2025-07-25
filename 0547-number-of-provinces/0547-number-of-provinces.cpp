class Solution {
public:
    int findCircleNum(vector<vector<int>>& isC) {
        int n = isC.size();
        vector<bool> vis(n,false);
        int c=0;
        for(int i = 0 ; i < n ; i++){
            
            queue<int> q;
            if(!vis[i]){
                c++;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int nn = q.front();q.pop();
                    for(int j=0;j<n;j++){
                        if(isC[nn][j]&&!vis[j]){
                            q.push(j);
                            vis[j]=true;
                        }
                    }
                }
            }

        }
        return c;
    }
};