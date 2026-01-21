class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int o = 0,n=nums.size();
        for(int num : nums)o|=num;
        int m=1<<(n-1);
        return o*m;
    }
};