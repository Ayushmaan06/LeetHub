class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for(vector<int> t : tasks)ans=min(ans,t[0]+t[1]);
        return ans;
    }
};