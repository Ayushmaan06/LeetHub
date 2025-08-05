class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char &c : s){
            if(isdigit(c)){
                if(!st.empty())st.pop();
            }
            else st.push(c);
        }
        string res="";
        while(!st.empty()){
            res+=st.top();st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};