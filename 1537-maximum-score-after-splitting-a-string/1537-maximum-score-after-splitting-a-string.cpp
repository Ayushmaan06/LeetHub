class Solution {
public:
    int maxScore(string s) {
        int lz=0,r1=0,n=s.length();
        for(int i = 1 ; i<n;i++){
            if(s[i-1]=='0')lz++;

        }
        int ans = INT_MIN;
        for(int i = n-1 ; i >0;i--){
            
            if(s[i]=='1'){
                r1++;
                ans=max(ans,lz+r1);
            }
            else{
                ans=max(ans,lz+r1);
                if(i!=n-1)lz--;
            }
        }
        return ans;
    }
};