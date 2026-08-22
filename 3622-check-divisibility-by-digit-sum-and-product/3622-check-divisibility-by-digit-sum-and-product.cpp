class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int a=0,p=1;
        for(char c : s){
            a+=(c-'0');p*=(c-'0');
        }
        return ((n % (a+p))==0);
    }
};