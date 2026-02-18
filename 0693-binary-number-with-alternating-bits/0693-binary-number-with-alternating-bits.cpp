class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lsb = -1;
        for(int i = 0 ; i < 32 ; i++)if(n&(1<<i))lsb=i;
        bool pz=true;
        for(int i = lsb ; i >= 0 ;i--){
            if(pz && (n&(1<<i)))pz=false;
            else if(!pz && !(n&(1<<i)))pz=true;
            else return false;
        }
        return true;
    }
};