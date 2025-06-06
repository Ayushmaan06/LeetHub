class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        stack<char> st;
        string res;
        int ptr = 0;

        for (char c : s) {
            st.push(c);
            freq[c - 'a']--;
            while (!st.empty()) {
                bool canPop = true;
                for (int i = 0; i < st.top() - 'a'; ++i) {
                    if (freq[i] > 0) {
                        canPop = false;
                        break;
                    }
                }
                if (canPop) {
                    res += st.top();
                    st.pop();
                } else {
                    break;
                }
            }
        }

        // Add any remaining characters in stack
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};
