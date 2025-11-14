class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0,e=1;
        while(true){
            e*=5;
            int x =n/e;
            if(x == 0)break;
            ans+=x; 
        }
        return ans;
    }
};