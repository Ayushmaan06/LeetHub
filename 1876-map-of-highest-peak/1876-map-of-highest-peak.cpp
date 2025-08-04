class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isw) {
        int n = isw.size(),m=isw[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isw[i][j]){
                    isw[i][j]=0;
                    q.push({i,j});
                }
                else{
                    isw[i][j]=-1;
                }
            }
        }
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()){
            auto[r,c]=q.front();q.pop();
            for(auto[nr,nc] : dir){
                int rr=r+nr,cc=c+nc;
                if(rr>=0&&cc>=0&&rr<n&&cc<m){
                    if(isw[rr][cc]==-1){
                        isw[rr][cc]=isw[r][c]+1;
                        q.push({rr,cc});
                    }
                }
            }

        }
        return isw;
    }
};