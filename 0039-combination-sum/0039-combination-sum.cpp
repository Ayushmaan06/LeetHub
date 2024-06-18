class Solution {
public:
    void solve(vector<int>& o, vector<int>& i, int k, vector<vector<int>>& r, int start, int currentSum) {
        if(currentSum > k) {
            return;
        }
        if(currentSum == k) {
            r.push_back(o);
            return;
        }
        for(int j = start; j < i.size(); j++) {
            // Skip duplicates
            if(j > start && i[j] == i[j-1]) continue;
            // Choose
            o.push_back(i[j]);
            // Explore
            solve(o, i, k, r, j, currentSum + i[j]); // j for unlimited usage of the same element
            o.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> o;
        vector<vector<int>> r;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        solve(o, candidates, target, r, 0, 0);
        return r;
    }
};