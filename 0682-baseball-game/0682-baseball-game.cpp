class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for(string s : op){
            if(s=="+"){
                int q1=st.top();st.pop();int q2=st.top();st.push(q1);st.push(q1+q2);
            }
            else if(s=="C")st.pop();
            else if(s=="D")st.push(2*(st.top()));
            else st.push(stoi(s));
        }
        int ans=0;
        while(st.size())ans+=st.top(),st.pop();
        return ans;
    }
};