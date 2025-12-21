class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(),c=0,j=0;
        for(int i = 0 ; i<n;i++){
            if(nums[i]==val)c++;
            else nums[j++]=nums[i];
        }
        return n-c;
    }
};