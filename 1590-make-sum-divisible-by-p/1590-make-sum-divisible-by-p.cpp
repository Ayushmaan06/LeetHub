class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum = (total_sum + num) % p;
        }
        
        if (total_sum == 0) {
            return 0;
        }
        
        unordered_map<int, int> prefix_mod;
        prefix_mod[0] = -1; 
        int prefix_sum = 0;
        int min_length = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target_mod = (prefix_sum - total_sum + p) % p;
            
            if (prefix_mod.find(target_mod) != prefix_mod.end()) {
                min_length = min(min_length, i - prefix_mod[target_mod]);
            }
            

            prefix_mod[prefix_sum] = i;
        }
        
        return min_length == nums.size() ? -1 : min_length;
    }
};