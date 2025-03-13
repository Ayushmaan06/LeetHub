class Solution {
public:
    bool isP(int m, vector<int> nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> mDiff(n + 1, 0);  
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1], v = queries[i][2];
            mDiff[l] -= v;
            if (r + 1 < n) mDiff[r + 1] += v;
        }

        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += mDiff[i];
            if (nums[i] + curr>0) return false; 
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size(), result = -1;  
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isP(m, nums, queries)) {
                result = m;
                r = m - 1;  
            } else {
                l = m + 1;  
            }
        }

        return result;
    }
};
