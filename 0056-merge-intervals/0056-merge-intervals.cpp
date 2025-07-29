class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        int n = in.size();
        int i = 0;
        vector<vector<int>> res;
        while (i < n) {
            int start = in[i][0];
            int end = in[i][1];
            while (i + 1 < n && end >= in[i + 1][0]) {
                i++;
                end = max(end, in[i][1]);
            }
            res.push_back({start, end});
            i++;
        }
        return res;
    }
};
