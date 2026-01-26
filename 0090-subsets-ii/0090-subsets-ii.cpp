class Solution {
public:
    set<vector<int>> res;
    void solve(vector<int>& nums, vector<int>& t, int i) {
        if (i == nums.size()) {
            res.insert(t);
            return;
        }
        solve(nums, t, i + 1);
        t.push_back(nums[i]);
        solve(nums, t, i + 1);
        t.pop_back(); 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> t;
        solve(nums, t, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
