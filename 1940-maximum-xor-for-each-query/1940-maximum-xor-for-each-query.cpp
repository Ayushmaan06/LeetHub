
class Solution {
private:
    int maxo(const std::vector<int> &nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
    
    int w(int m, int t) {
        int j = 0;
        for (int i = 0; i < m; i++) {
            if (!(t & (1 << i))) {
                j += (1 << i); 
            }
        }
        return j;
    }

public:
    std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
        int n = nums.size();
        std::vector<int> res(n);
        int currentXor = maxo(nums); 

        for (int i = 0; i < n; i++) {
            int mx = w(maximumBit, currentXor);
            res[i] = mx;
            currentXor ^= nums.back(); 
            nums.pop_back(); 
        }
        return res;
    }
};
