class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n =0;
        int k  = start^goal;
        while(k>0){
            k=k&(k-1);
            n++;
        }
        return n;
    }
};