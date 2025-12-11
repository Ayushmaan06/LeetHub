class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& v) {
        unordered_map<int,vector<int>> x,y;
        sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        for(vector<int> bb : v){
            x[bb[0]].push_back(bb[1]);
            y[bb[1]].push_back(bb[0]);
        }
        int ans=0;
        for(vector<int> bb : v){
            int xx=bb[0],yy=bb[1];
            int i = lower_bound(y[yy].begin(),y[yy].end(), xx)-y[yy].begin(), j = lower_bound(x[xx].begin(),x[xx].end(), yy)-x[xx].begin();
            if( i > 0 && j > 0 && i < y[yy].size()-1 && j < x[xx].size()-1)ans++;
        }
        return ans;
    }
};