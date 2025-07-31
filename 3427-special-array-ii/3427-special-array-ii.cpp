class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& qu) {
        vector<int> vp;
        for (int i = 1; i < nums.size(); ++i) {
            if ((nums[i] & 1) == (nums[i - 1] & 1))
                vp.push_back(i);          
        }
        vector<bool> res;
        for (const auto& q : qu) {
            int l = q[0], h = q[1];
            auto first = lower_bound(vp.begin(), vp.end(), l + 1);
            auto last  = upper_bound(vp.begin(), vp.end(), h);
            res.push_back(first == last); 
        }
        return res;
    }
};