class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int c = 0; 
        for (int num : nums) {
            if (num == 1) c++;
        }

        if (c == 0 || c == n) return 0;

        int maxOnes = 0;
        int currentOnes = 0;
        int i = 0;

        
        for (int j = 0; j < 2 * n; ++j) {
            if (nums[j % n] == 1) currentOnes++;

            if (j - i + 1 > c) {
                if (nums[i % n] == 1) currentOnes--;
                i++;
            }

            maxOnes = max(maxOnes, currentOnes);
        }

        
        return c - maxOnes;
    }
};