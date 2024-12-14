class Solution {
public:
long long continuousSubarrays(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        long long ans = 0;
        multiset<int> window;

        while (r < n) {
            window.insert(nums[r]);
            
            // Maintain the window such that max - min <= 2
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[l]));
                l++;
            }
            
            // All subarrays ending at `r` and starting from any index between `l` and `r` are valid
            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
};
