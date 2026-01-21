class Solution {
public:
    int tribonacci(int n) {
        int n0=0,n1=1,n2=1,ans;
        if(n==0)return 0;
        else if(n==1 || n==2)return 1;
        n-=2;
        while(n--){
            ans=n0+n2+n1;
            n0=n1;
            n1=n2;
            n2=ans;
        }
        return ans;
    }
};