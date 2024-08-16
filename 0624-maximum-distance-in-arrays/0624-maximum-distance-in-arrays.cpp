class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        int maxDist = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            maxDist = max(maxDist, abs(arrays[i].back() - minVal));
            maxDist = max(maxDist, abs(maxVal - arrays[i].front()));
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }

        return maxDist;
    }
};