class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n);
        mx[0] = nums[0];
        for (int i = 1; i < n; i++) {
            mx[i] = max(mx[i - 1], nums[i]);
        }
        vector<int> mi(n);
        mi[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mi[i] = min(mi[i + 1], nums[i]);
        }
        vector<int> res(n);
        int start = 0; 
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || mx[i] <= mi[i + 1]) {
                for (int j = start; j <= i; j++) res[j] = mx[i];
                start = i + 1; 
            }
        }

        return res;
    }
};