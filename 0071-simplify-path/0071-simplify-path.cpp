class Solution {
public:
    string simplifyPath(string p) {
        int n = p.length();
        stack<string> st;
        int i = 0;
        while (i < n) {
            while (i < n && p[i] == '/') i++;   
            if (i >= n) break;
            int j = i;
            while (j < n && p[j] != '/') j++;
            string dir = p.substr(i, j - i);
            if (dir == "..") {
                if (!st.empty()) st.pop();
            }
            else if (dir != ".") {
                st.push(dir);
            }

            i = j;
        }
        string ans;
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};
