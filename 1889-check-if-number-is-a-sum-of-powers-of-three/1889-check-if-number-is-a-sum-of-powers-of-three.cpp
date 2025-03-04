class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;  
            }
            n /= 3;  // Reduce n by dividing by 3
        }
        return true;
    }
};
