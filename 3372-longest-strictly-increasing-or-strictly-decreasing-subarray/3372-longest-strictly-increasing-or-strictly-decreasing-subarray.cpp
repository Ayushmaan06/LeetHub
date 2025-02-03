class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1, dec=1 , ai=0 , di =0;
        int prev = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]>prev){
                inc++;
                di = max(di , dec);
                dec=1;
        
            }
            else if(nums[i]<prev){
                dec++;
                ai=max(ai, inc);
                inc = 1;
                
            }
            else if(nums[i]==prev){
                ai=max(ai, inc);
                inc = 1;
                di = max(di , dec);
                dec=1;
            }
            prev = nums[i];
        }
        return max({ai, di, inc, dec});
    }
};