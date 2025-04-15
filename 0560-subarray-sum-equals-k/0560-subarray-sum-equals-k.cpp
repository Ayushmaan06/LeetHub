class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sC;
        sC[0] = 1;
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            if (sC.count(sum - k)) {
                count += sC[sum - k];
            }
            sC[sum]++;
        }
        return count;
    }
};