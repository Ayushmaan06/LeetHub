class Solution {
public:
    int numWaterBottles(int nB, int nE) {
        int ans=0,r=0;
        while(nB>0){
            ans+=nB;
            int q = nB/nE;
            r += nB%nE;
            nB=q;
            if(r>=nE){
                nB+=r/nE;
                r=r-(r/nE)*nE;
            }
        }
        return ans;
    }
};