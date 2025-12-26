class Solution {
public:
    int bestClosingTime(string cc) {
        int n = 0, y = 0,s=cc.size();
        for(char c : cc)if(c=='N')n++;
        int mp=n,j=s;
        for(int i = s-1 ; i >=0 ; i--){
            if(cc[i]=='Y')y++;
            else n--;
            int p = n+y;
            cout<<p;
            if(p<=mp){mp=p;j=i;}
        }
        return j;
    }
};