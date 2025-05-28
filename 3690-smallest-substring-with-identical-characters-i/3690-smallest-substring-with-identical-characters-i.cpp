class Solution {
public:
    char opp(char i){
        if(i=='0')return '1';
        else return '0';
    }
    bool isP(int m , string s,int o){
        int n = s.length();
        char prev = s[0];
        int rl=1;
        if(m==1){
            int need0=0,need=0;
            for(int i=0;i<n;i++){
                if(i%2==0) {if(s[i]=='1') need0++;}
                else {if(s[i]=='0') need0++;}
            }
            int need1 = 0;
            // case - '101010...'
            for(int i=0;i<n;i++){
                if(i%2==1) {if(s[i]=='1') need1++;}
                else {if(s[i]=='0') need1++;}
            }
            need = min(need1, need0);
            return need <= o;
        }
        for(int i = 1 ; i < n ; i++){
            if(prev==s[i]){
                rl++;
                if(rl==m+1){
                    if(o>0){
                        o--;
                        rl=0;
                        prev=opp(prev);
                    }
                    else return false;
                }
            }
            else{
                prev=s[i];rl=1;
            }
        }
        return true;
    }
    int minLength(string s, int numOps) {
        int n = s.length();
        int l = 1 , h = n;
        int ans=INT_MAX;
        while(l<=h){
            int m = l+(h-l)/2;
            if(isP(m,s,numOps)){
                ans=min(ans,m);
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};