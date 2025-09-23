class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        while(n){
            int x=log2(n);
            int l = pow(2,x), h = pow(2,x+1);
            if(abs(n-l)<abs(n-h))n=abs(n-l);
            else n=abs(n-h);
            ans++;
        }
        return ans;
    }
};
