class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=INT_MIN;
        int currmax=values[0]-1;
        for(int i = 1; i<values.size();i++){
            ans = max(ans,currmax+values[i]);
            currmax-=1;
            currmax=max(currmax,values[i]-1);
        }
        return ans;
    }
};