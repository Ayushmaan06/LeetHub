class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c1=0,c2=0,ans;
        for(int i = 0 ; i < 32 ; i++){
            int y=1<<i;
            if(num2 & y)c2++;
            if(num1 & y)c1++;
        }
        if(c1==c2)return num1;
        if(c1>c2){
            ans=num1;
            int x=c1-c2;
            while(x--)ans=ans&(ans-1);
        }
        else{
            ans=num1;
            int x=c2-c1;
            while(x--){
                for(int i = 0 ; i < 32 ; i++){
                    int y=1<<i;
                    if(!(ans&y)){
                        ans=ans|y;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};