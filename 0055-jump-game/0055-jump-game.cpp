class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =  nums.size(),nxt=n-1;
        if(n==1)return true;
        for(int i = n-2 ; i >=0 ; i--){
            int nxt1 = i+nums[i];
            if(nxt<=nxt1)nxt=i;
        }
        return nxt==0;
    }
};
