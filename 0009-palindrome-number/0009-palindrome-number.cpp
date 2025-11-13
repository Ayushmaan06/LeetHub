class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n=s.length();
        int i =0;
        while(i<n/2){
            if(s[i]!=s[n-i-1])return false;
            i++;
        }
        return true;
    }
};