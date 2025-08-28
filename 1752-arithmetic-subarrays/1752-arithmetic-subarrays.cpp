class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        
        for (int q = 0; q < l.size(); q++) {
            int left = l[q], right = r[q];
            int len = right - left + 1;
            
            int mn = INT_MAX, mx = INT_MIN;
            for (int i = left; i <= right; i++) {
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
            }
            
            if (len <= 2) {
                res.push_back(true);
                continue;
            }
            
            if ((mx - mn) % (len - 1) != 0) {
                res.push_back(false);
                continue;
            }
            
            int d = (mx - mn) / (len - 1);
            if (d == 0) {
                // all numbers must be equal
                bool ok = true;
                for (int i = left; i <= right; i++) {
                    if (nums[i] != mn) { ok = false; break; }
                }
                res.push_back(ok);
                continue;
            }
            
            unordered_set<int> seen;
            bool ok = true;
            for (int i = left; i <= right; i++) {
                if ((nums[i] - mn) % d != 0) { ok = false; break; }
                int pos = (nums[i] - mn) / d;
                if (seen.count(pos)) { ok = false; break; }
                seen.insert(pos);
            }
            res.push_back(ok);
        }
        return res;
    }
};
