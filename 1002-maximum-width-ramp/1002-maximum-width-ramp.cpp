class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        int minIndex = v[0].second;
        int maxWidth = 0;

        for (int i = 1; i < v.size(); i++) {
            maxWidth = max(maxWidth, v[i].second - minIndex);
            minIndex = min(minIndex, v[i].second);
        }

        return maxWidth;
    }
};