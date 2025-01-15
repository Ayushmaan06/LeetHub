class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count_ones_in_num2 = 0;
        int num2_copy = num2;

        // Count the number of 1 bits in num2
        while (num2_copy > 0) {
            count_ones_in_num2 += (num2_copy & 1);
            num2_copy >>= 1;
        }

        // Start constructing the result from num1
        int result = 0;
        int count_ones_in_result = 0;

        // Go through the bits of num1 and try to set as many 1s as possible in the result
        for (int i = 30; i >= 0; --i) { // From highest bit to lowest bit
            int bit_in_num1 = (num1 >> i) & 1;
            if (bit_in_num1 == 1 && count_ones_in_result < count_ones_in_num2) {
                // Set this bit to 1 in the result if we still need more 1s
                result |= (1 << i);
                count_ones_in_result++;
            }
        }

        // If we still have 1 bits to place, place them in the lowest positions
        for (int i = 0; i < 31; ++i) {
            if ((result >> i) & 1) continue;  // Skip bits that are already set
            if (count_ones_in_result < count_ones_in_num2) {
                result |= (1 << i);
                count_ones_in_result++;
            }
        }

        return result;
    }
};
