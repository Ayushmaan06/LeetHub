class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return n;
        if(n==2) return 5;
        long long x = 4*(n-1);
        x+=coloredCells(n-1);
        return x;
    }
};