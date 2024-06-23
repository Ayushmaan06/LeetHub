class Solution {
public:
    int longestValidParentheses(string s) {
    int maxLen = 0;
    stack<int> indexStack;
    indexStack.push(-1); // Base for the first valid substring
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            indexStack.push(i);
        } else {
            indexStack.pop();
            if (indexStack.empty()) {
                indexStack.push(i); // New base for the next valid substring
            } else {
                maxLen = max(maxLen, i - indexStack.top());
            }
        }
    }
    return maxLen;
}
};