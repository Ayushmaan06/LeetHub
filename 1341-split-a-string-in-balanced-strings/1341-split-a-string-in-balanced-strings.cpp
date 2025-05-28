class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length();
        int c=1;
        int ans=0;
        if(s[0]=='R')c=-1;
        for(int i = 1 ; i < n ; i++){
            char ch=s[i];
            if(ch=='R')c-=1;
            else c+=1;
            if(c==0)ans++;
        }
        return ans;
    }
};