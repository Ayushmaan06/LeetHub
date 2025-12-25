class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string t = "";
                while (!st.empty() && st.top() != "[") {
                    t = st.top() + t;
                    st.pop();
                }
                st.pop(); 
                string num = "";
                while (!st.empty() && st.top().size() == 1 && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }
                int k = stoi(num);
                string repeated = "";
                for (int j = 0; j < k; j++) repeated += t;
                st.push(repeated);
            } else {
                st.push(string(1, s[i]));
            }
        }
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
