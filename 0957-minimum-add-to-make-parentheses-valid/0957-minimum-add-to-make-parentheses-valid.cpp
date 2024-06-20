class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> v;
        int c=0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i]=='('){
                v.push(s[i]);
            }
            if(s[i]==')'){
                if(v.empty()){
                    c++;
                }
                else{
                    v.pop();
                }
            }
        }
        if(v.empty())   return c;
        else    return(c+v.size());
    }
};