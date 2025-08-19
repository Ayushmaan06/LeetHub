#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int j = i;
                while(i<n && nums[i]==0){
                    ans+=i-j+1;
                    i++;
                }
                
            }
        }
        return ans;
    }
};