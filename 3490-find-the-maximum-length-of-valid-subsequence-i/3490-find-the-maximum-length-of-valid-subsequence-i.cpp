class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int no = 0, ne = 0;

        // Count odd and even numbers
        for (int n : nums) {
            if (n % 2 == 0)
                ne++;
            else
                no++;
        }

        // Function to calculate longest alternating sequence starting with a given parity
        auto getAlternatingLength = [&](int startParity) {
            int count = 0;
            int expectedParity = startParity;  
            for (int n : nums) {
                if (n % 2 == expectedParity) {
                    count++;
                    expectedParity ^= 1; 
                }
            }
            return count;
        };
        int altStartEven = getAlternatingLength(0);
        int altStartOdd = getAlternatingLength(1);

        return max({no, ne, altStartEven, altStartOdd});
    }
};
