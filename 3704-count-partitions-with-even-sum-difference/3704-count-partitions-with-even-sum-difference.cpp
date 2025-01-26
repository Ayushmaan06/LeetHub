class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int  n = nums.size();
        int ls=0,rs=0,ans=0;
        for(int num : nums){
            ls+=num;
        }
        for(int i = n-1 ; i>0 ; i--){
            ls-=nums[i];
            rs+=nums[i];
            int k = abs(ls-rs)%2;
            if(!k)ans++;

        }
        return ans;
    }
};