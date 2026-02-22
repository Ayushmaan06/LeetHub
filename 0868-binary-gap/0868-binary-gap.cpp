class Solution {
public:
    int binaryGap(int n) {
        int p =-1, ans = INT_MIN;
        for(int i = 0 ; i < 32 ; i++){
            if(n&(1<<i)){
                if(p==-1)ans=0;
                else ans=max(ans,i-p);
                p=i;
            }
        }
        return ans;
    }
};