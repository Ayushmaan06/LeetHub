#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st; // Stack to keep track of '(' indices
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                // Push the index of '(' onto the stack
                st.push(i);
            } else if (s[i] == ')') {
                // When ')' is found, reverse the substring between the current ')' and the last '('
                int start = st.top();
                st.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        // Remove all parentheses from the string
        string result;
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }
        return result;
    }
};