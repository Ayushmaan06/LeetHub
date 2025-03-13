class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> v(n + 1, 0); 
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            v[l]--; 
            v[r + 1]++; 
        }

        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += v[i];
            if (nums[i] + curr > 0) return false;
        }

        return true;
    }
};
