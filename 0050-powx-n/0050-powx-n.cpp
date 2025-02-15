class Solution {
public:
    double p(double x, int n){
        if(n==0)return 1;
        if(n==1)return x;
        if(n%2){
            return p(x*x,n/2)*x;
        }
        else{
            return p(x*x,n/2);
        }
    }
    double myPow(double x, int n) {
        if(n<0)return(1/p(x,n));
        return p(x,n);
    }
};