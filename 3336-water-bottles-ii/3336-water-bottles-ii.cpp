class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fi=numBottles,ex=numExchange,em=0,d=0;
        if(ex>fi)return fi;
        d+=fi;
        em+=fi;
        fi=0;

        while(em>=ex){
            em-=ex;
            ex++;
            d++;
            em++;

        }
        return d;
    }
};