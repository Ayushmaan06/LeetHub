class Solution {
public:
    bool isPalindrome(int x) {
        int r=0,og=x;
        while(x>0){

            int digit = x % 10;
            x /= 10;
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && digit > 7)) return 0;
            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && digit < -8)) return 0;

            r = r * 10 + digit;
        }
        if(r==og)
            return true;
        else
            return false;
    }
};