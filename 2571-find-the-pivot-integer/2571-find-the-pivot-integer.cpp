class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)return 1;
        for(int i = 1;i<n;i++){
            int ts = n*(n+1)/2;
            int cs = i*(i+1)/2;
            if(ts-cs+i==cs)return i;
        }
        return -1;
    }
};