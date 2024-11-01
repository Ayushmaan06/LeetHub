class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int x=0;
        char p=s[0];
        for(char c : s){
            if(p==c){
                x++;
            }
            else{
                x=1;
                p=c;
            }
            if(x<3){
                res+=c;
            }
            if(x>=3){
                x--;
            }
        }
        return res;
    }
};