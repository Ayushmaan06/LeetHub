class Solution {
public:
    long long flowerGame(int n, int m) {
        long long e1 = n/2 , e2 = m/2,o1,o2;
        o1=n-e1;o2=m-e2;
        return ((e1*o2)+(o1*e2));
    }
};