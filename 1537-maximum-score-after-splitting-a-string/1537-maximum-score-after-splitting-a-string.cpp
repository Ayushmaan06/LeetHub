class Solution {
public:
    int maxScore(string s) {
        int lz=0,r1=0,n=s.length(),ans=0;
        for(int i = 1 ; i < n ; i++){
            if(s[i-1]=='0')lz++;
        }
        for(int i = n-1 ; i>0;i--){
            if(s[i]=='1'){
                r1++;
                ans=max(lz+r1,ans);
            }
            else{
                ans=max(lz+r1,ans);
                if(i!=n-1)lz--;
            }
        }
        return ans;
    }
};