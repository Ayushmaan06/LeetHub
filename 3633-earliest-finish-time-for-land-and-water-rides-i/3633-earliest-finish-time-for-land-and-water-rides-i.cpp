class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size(), ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            int sc=landStartTime[i]+landDuration[i];
            for(int j = 0 ; j < m ;j++){
                int tc=sc;
                if(waterStartTime[j]>sc)tc=waterStartTime[j];
                tc+=waterDuration[j];
                ans=min(ans,tc);
            }
        }
        for(int i = 0 ; i < m ; i++){
            int sc=waterStartTime[i]+waterDuration[i];
            for(int j = 0 ; j < n ;j++){
                int tc=sc;
                if(landStartTime[j]>sc)tc=landStartTime[j];
                tc+=landDuration[j];
                ans=min(ans,tc);
            }
        }
        return ans;
    }
};