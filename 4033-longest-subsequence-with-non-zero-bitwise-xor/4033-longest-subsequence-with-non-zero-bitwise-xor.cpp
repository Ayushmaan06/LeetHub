class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0,z=0;
        for(int i : nums){
            if(i==0)z++;
            x=x^i;
        }
        if(z==nums.size())return 0;
        if(x==0)return nums.size()-1;
        return nums.size();
    }
};