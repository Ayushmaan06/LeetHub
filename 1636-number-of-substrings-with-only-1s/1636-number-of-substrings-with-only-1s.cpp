#define ll long long
class Solution {
public:
    int numSub(string s) {
        ll mod = 1e9+7;
        ll ans=0,n=s.length();
        for(int i = 0; i < n ;){
            ll c=0;
            while(i<n && s[i]=='1'){c++;i++;}
            ans+=(c*(c+1)/2)%mod;
            i++;
        }
        return ans;
    }
};