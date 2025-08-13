class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end()); 
        vector<int> last = intervals[0];
        int ans = 0, n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (last[1] > intervals[i][0]) {
                ans++;
                if (intervals[i][1] < last[1]) last = intervals[i];
            } else {
                last = intervals[i];
            }
        }
        return ans;
    }
};
