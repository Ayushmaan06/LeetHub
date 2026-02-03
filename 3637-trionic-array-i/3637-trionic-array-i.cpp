class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1,n=nums.size();if(n<3)return false;
        while(i<n && nums[i]>nums[i-1])i++;
        if(i==1 || i==n)return false;
        int p = i;
        while(i<n && nums[i]<nums[i-1])i++;
        if(i==n)return false;
        while(i<n && nums[i]>nums[i-1])i++;
        return i==n;
    }
};