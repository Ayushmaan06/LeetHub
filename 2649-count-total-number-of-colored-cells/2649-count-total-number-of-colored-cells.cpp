class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return 1;
        long long x = n-1;
        x=x*(4+4*x)/2;
        return ++x;
    }
};