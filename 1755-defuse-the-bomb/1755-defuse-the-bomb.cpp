class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();vector<int>res(n,0);
        if(k==0)return res;
        int st,en;
        if(k>0){
            st=1;
            en=k;
        }
        else{
            st=n+k;
            en=n-1;
        }
        int ans=0;
        for(int i=st;i <= en;i++)ans+=code[i];
        res[0]=ans;
        for(int i =1;i<n;i++){
            ans-=code[st];
            st=(st+1)%n;
            en=(en+1)%n;
            ans+=code[en];
            res[i]=ans;
        }
        return res;
    }
};