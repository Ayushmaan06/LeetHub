class Solution {
public:
    bool isPathCrossing(string path) {
       int x=0;
       int y=0;
       set<array<int, 2>> myset;
       myset.insert({0,0});
       for (char chr:path){
            if(chr=='N'){
                y+=1;
            }
            else if(chr=='S'){
                y-=1;
            }
            else if(chr=='E'){
                x+=1;
            }
            else{
                x-=1;
            }


            if(myset.find({x,y})!=myset.end()){
                return true;
            }

            myset.insert({x,y});

        }
        return false;
    }
};