class Solution {
public:
    long long minEnd(int n, int x) {
        long long res=x;
        int i = 0 , j = 0;
        while(i<31){
            while(x&(1LL<<j))j++;
            if((n-1)&(1LL<<i))res=res | (1LL<<j);
            i++;j++;
        }
        return res;
    }
};