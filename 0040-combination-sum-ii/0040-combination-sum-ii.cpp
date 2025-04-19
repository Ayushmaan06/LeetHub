
class Solution {
public:
    void solve(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& result, 
               int target, int start) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i-1]) continue;
            
            // Skip if current candidate is too large
            if (candidates[i] > target) break;
            
            curr.push_back(candidates[i]);
            solve(candidates, curr, result, target - candidates[i], i + 1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort candidates first for handling duplicates efficiently
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates, curr, result, target, 0);
        return result;
    }
};