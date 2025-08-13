class Solution {
public:
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> res(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        res[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int w = pq.top().first,r=pq.top().second.first,c=pq.top().second.second;pq.pop();
            if(r==n-1 && c==m-1) return w;
            if(w>res[r][c]) continue;
            for(auto[rr,cc] : dir){
                int nr=rr+r,nc=cc+c;
                if(nr>=0 && nc>=0 && nr<n && nc< m){
                    int t=max(w,abs(heights[nr][nc]-heights[r][c]));
                    if(t<res[nr][nc]){
                        res[nr][nc]=t;
                        pq.push({t,{nr,nc}});
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
};