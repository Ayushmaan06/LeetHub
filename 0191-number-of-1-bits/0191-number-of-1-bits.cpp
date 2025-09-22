class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            int x=1<<i;
            if(n&x)ans++;
        }
        return ans;
    }
};