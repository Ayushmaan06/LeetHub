class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> nextIdx(n, n);
        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextIdx[i] = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c <= 1; c++) {
                if(c) dp[i][c]=max(events[i][2],dp[i+1][1]);
                else dp[i][c]=max(events[i][2]+ dp[nextIdx[i]][1],dp[i+1][0]);
            }
        }
        return dp[0][0];
    }
};
