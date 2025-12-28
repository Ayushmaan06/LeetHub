class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int n = g.size(),m=g[0].size();
        int i = 0, j = m-1,c=0;
        for( ; i<n;i++ ){
            int r=0;
            while(j>=0 && g[i][j]<0)r++,j--;
            c+=r*(n-i);
        }
        return c;
    }
};