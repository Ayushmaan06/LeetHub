class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        stack<int> st;
        string res = "";
        int num = 1; 
        for (int i = 0; i <= n; ++i) {
            st.push(num++);
            
        
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        return res;
    }
};
