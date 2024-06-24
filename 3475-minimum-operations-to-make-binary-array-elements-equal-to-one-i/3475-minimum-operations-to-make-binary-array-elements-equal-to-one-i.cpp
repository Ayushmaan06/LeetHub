class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0;
        int c = 0;
        int n = nums.size();
        int k =3;
        while (i < n) {
            if (nums[i] == 0) {
                if (i + k > n) return -1; // Not enough elements to flip
                for (int j = i; j < i + k; j++) {
                    nums[j] = nums[j] ^ 1; // Flip the bit
                }
                c++;
            }
            i++;
        }
        
        if (find(nums.begin(), nums.end(), 0) == nums.end()) return c;
        else return -1;

    }
};