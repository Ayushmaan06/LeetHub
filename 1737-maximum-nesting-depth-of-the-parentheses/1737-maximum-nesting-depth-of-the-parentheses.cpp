class Solution {
public:
    int maxDepth(string s) {
        int t=0,a=0;
        for(char c : s){
            if(c=='(')t++;
            else if (c==')')t--;
            a=max(a,t);
        }
        return a;
    }
};