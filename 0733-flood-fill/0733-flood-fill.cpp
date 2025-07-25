class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        if(img[sr][sc]==color)return img;
        queue<pair<int,int>>q;
        int n = img.size(),m=img[0].size();
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        q.push({sr,sc});
        int og = img[sr][sc];
        img[sr][sc]=color;
        while(!q.empty()){
            auto[r,c]=q.front();q.pop();
            for(auto[nr,nc]:dir){
                int rr=r+nr,cc=c+nc;
                if(rr>=0 && cc>=0 && rr<n && cc<m && img[rr][cc]==og){
                    img[rr][cc]=color;
                    q.push({rr,cc});
                }
            }
        }
        return img;
    }
};