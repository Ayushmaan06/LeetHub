#define ll long long
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        ll t=0LL;string s = to_string(n),r;
        for(char c: s)if(c!='0')r=r+c;
        for(char c: r)t+=(c-'0');
        ll k=stoll(r);
        return k*t;
    }
};