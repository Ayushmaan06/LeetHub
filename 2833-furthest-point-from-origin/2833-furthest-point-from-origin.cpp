class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lc=0,rc=0,_c=0;
        for(char c : moves){
            if(c=='L')lc++;
            else if(c=='R')rc++;
            else _c++;
        }
        return abs(lc-rc)+_c;
    }
};