class Solution {
public:
    int findComplement(int n) {
        if (n == 0) return 1;
        int bitLength = 0;
        int temp = n;
        while (temp > 0) {
            bitLength++;
            temp >>= 1;
        }

        unsigned int mask = (1U << bitLength) - 1;

        return  mask-n;
    }
};