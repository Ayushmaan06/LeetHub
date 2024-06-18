#include <vector>
#include <algorithm>

class Solution {
private:
    void solve(vector<int>& candidates, int start, vector<int>& current, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            if (i > start && candidates[i] == candidates[i-1]) continue; // Skip duplicates
            
            current.push_back(candidates[i]);
            solve(candidates, i + 1, current, target - candidates[i], result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        solve(candidates, 0, current, target, result);
        return result;
    }
};