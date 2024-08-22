class Solution {
public:
    int findComplement(int n) {
        // Handle the edge case where n is 0
        if (n == 0) return 1;

        // Calculate the bit length of n
        int bitLength = 0;
        int temp = n;
        while (temp > 0) {
            bitLength++;
            temp >>= 1;
        }

        // Create a mask with the same number of bits as n, all set to 1
        unsigned int mask = (1U << bitLength) - 1;

        // Flip the bits of n using the mask
        return n ^ mask;
    }
};