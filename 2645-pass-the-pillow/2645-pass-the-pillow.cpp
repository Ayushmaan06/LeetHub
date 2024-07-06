class Solution {
public:
    int passThePillow(int n, int time) {
        int q = time/(n-1) , r = time%(n-1);
        if(r==0){
            if(q%2)return n;
            else return 1;
        }
        else{
            if(q%2){
                return (n-r);
            }
            else{
                return (r+1);
            }
        }
    }
};