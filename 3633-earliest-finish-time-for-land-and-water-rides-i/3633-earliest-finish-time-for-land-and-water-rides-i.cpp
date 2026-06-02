class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int finish1 = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) finish1 = min(finish1, landStartTime[i] + landDuration[i]);
        int finish2 = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) finish2 = min(finish2, max(waterStartTime[i], finish1) + waterDuration[i]);
        int finish3 = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) finish3 = min(finish3, waterStartTime[i] + waterDuration[i]);
        int finish4 = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) finish4 = min(finish4, max(landStartTime[i], finish3) + landDuration[i]);
        return min(finish2, finish4);
    }
};