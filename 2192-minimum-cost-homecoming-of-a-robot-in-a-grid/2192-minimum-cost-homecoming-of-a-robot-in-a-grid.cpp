class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int x=startPos[0], y=startPos[1];
        int r=homePos[0], c=homePos[1];
        int ans=0;
        for(int i=x+1; i<=r; i++) ans+=rowCosts[i];
        for(int i=x-1; i>=r; i--) ans+=rowCosts[i];
        for(int i=y+1; i<=c; i++) ans+=colCosts[i];
        for(int i=y-1; i>=c; i--) ans+=colCosts[i];
        return ans;
    }
};