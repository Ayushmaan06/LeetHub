class Solution {
public:
    int minAddToMakeValid(string s) {
        int i=0,k=0;
        for(char c : s){
            if(c==')' && i==0){
                k++;
            }
            if(c=='('){
                i++;
            }
            if(c==')' && i>0){
                i--;
            }

        }
        return i+k;
    }
};