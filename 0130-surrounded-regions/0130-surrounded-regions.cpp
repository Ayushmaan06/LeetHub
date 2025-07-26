class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size();
        queue<pair<int,int>> q;
        for(int i=0 ; i<m;i++){
            if(b[0][i]=='O'){
                b[0][i]='A';
                q.push({0,i});
            }
            if(b[n-1][i]=='O'){
                b[n-1][i]='A';
                q.push({n-1,i});
            }
        }
        for(int i=0 ; i<n;i++){
            if(b[i][0]=='O'){
                b[i][0]='A';
                q.push({i,0});
            }
            if(b[i][m-1]=='O'){
                b[i][m-1]='A';
                q.push({i,m-1});
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()){
            auto[r,c]=q.front();q.pop();
            for(auto[rr,cc] : dir){
                int nr=r+rr,nc=c+cc;
                if(nr>=0 && nc>=0 && nr<n &&nc<m){
                    if(b[nr][nc]=='O'){
                        b[nr][nc]='A';
                        q.push({nr,nc});
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(b[i][j]=='A')b[i][j]='O';
                else b[i][j]='X';
            }
        }
    }
};