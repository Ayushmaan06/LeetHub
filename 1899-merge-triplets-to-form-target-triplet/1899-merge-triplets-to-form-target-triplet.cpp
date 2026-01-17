class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& tt) {
        bool a=false,b=false,c=false;
        for(vector<int> t : triplets){
            int x=t[0],y=t[1],z=t[2];
            if(x>tt[0] || y>tt[1] || z>tt[2])continue;
            if(x==tt[0])a=true;
            if(y==tt[1])b=true;
            if(z==tt[2])c=true;
            if(a && b && c)return true;
        }
        return a && b && c;
    }
};
