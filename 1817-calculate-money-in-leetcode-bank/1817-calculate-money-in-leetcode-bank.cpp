class Solution {
public:
    int totalMoney(int n) {
        float q = n/7, r = n%7;
        float s = (q/2)*(2*28 + (q-1)*7);
        q++;
        s+=(r/2)*(2*q + r-1);
        return s;
    }
};