class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double wt=0,lastend=0,n=c.size();
        for(int i = 0 ; i < n ; i ++){
            if(lastend<c[i][0]){
                wt+=c[i][1];
                lastend=c[i][1]+c[i][0];
            }
            else{
                wt+=c[i][1]+lastend-c[i][0];
                lastend+=c[i][1];
            }
        }
        double ans = wt/n;
        return ans;
    }
};