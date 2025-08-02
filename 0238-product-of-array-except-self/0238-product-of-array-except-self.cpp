class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int hz=0;
        int p=1;
        for(int n : nums){
            if(n)p*=n;
            else hz++;
        }
        vector<int> ans(nums.size(),0);
        if(hz>1)return ans;
        if(hz==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){ans[i]=p;return ans;}
            }
        }
        for(int  &n : nums){
            n=p/n;
        }
        return nums;
    }
};