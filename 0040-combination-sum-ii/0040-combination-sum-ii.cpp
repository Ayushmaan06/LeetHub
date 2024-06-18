class Solution {
public:
    void solve(vector<int>& i, vector<int> o, int k, int s, vector<vector<int>>& r, int start) {
        if (s > k) {
            return;
        }
        if (s == k) {
            sort(o.begin(), o.end());
            r.push_back(o);
            return;
        }
        for (int j = start; j < i.size(); ++j) {
            // Skip duplicates
            if (j > start && i[j] == i[j - 1]) continue;
            o.push_back(i[j]);
            solve(i, o, k, s + i[j], r, j + 1);
            o.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(candidates, current, target, 0, result, 0);
        return result;
    }
};
