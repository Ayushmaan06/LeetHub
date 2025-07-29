class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bb(32, -1);
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 32; b++) {
                if (nums[i] & (1 << b)) bb[b] = i;
            }
            int ans = 1;
            for (int b = 0; b < 32; b++) {
                if (bb[b] != -1) {
                    ans = max(ans, bb[b] - i + 1);
                }
            }
            nums[i] = ans;
        }
        return nums;
    }
};
