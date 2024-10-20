class Solution {
public:
    bool parseBoolExpr(string expression) {
    stack<char> st;

    for (char ch : expression) {
        if (ch == ')') {
            vector<char> subExpr;
            while (st.top() != '(') {
                subExpr.push_back(st.top());
                st.pop();
            }
            st.pop(); // pop the '('

            char operatorChar = st.top();
            st.pop(); // pop the operator

            bool result;
            if (operatorChar == '&') {
                result = true;
                for (char c : subExpr) {
                    if (c == 'f') {
                        result = false;
                        break;
                    }
                }
            } else if (operatorChar == '|') {
                result = false;
                for (char c : subExpr) {
                    if (c == 't') {
                        result = true;
                        break;
                    }
                }
            } else if (operatorChar == '!') {
                result = (subExpr[0] == 'f');
            }

            st.push(result ? 't' : 'f');
        } else if (ch != ',') {
            st.push(ch);
        }
    }

    return st.top() == 't';
}
};