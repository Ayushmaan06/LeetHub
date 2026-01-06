class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int i =0,j=0,n=nums.size(),rs=0,ans=INT_MAX;
        while(j<n){
            rs+=nums[j];
            while(rs>=t){
                ans=min(ans,j-i+1);
                rs-=nums[i];i++;
            }
            j++;
        }
        return ans==INT_MAX? 0 : ans;
    }
};