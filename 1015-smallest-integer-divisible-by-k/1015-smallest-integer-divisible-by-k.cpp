class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k== 1)return k;
        if(k%2==0 || k%5==0 )return -1;
        int x = 0,i=0;
        while(true){
            int x = x*10;x++;x=x%k;
            if(x==0)return i+1;
            i++;
        }
    }
};