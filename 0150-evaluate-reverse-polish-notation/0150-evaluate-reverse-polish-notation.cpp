#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int n2 = st.top(); st.pop();
                int n1 = st.top(); st.pop();
                if (t == "+") st.push(n1 + n2);
                else if (t == "-") st.push(n1 - n2);
                else if (t == "*") st.push(n1 * n2);
                else if (t == "/") st.push(n1 / n2);
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
