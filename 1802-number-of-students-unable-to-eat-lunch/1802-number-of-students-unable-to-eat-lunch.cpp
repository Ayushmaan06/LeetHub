class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> dq;    
        stack<int> st;
        int n = sandwiches.size();
        for (int i = 0; i < n; i++) {
            dq.push_back(students[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }

        int rotations = 0;
        while (!st.empty() && rotations < dq.size()) {
            int c = dq.front();
            int s = st.top();
            if (c == s) {
                st.pop();
                dq.pop_front();
                rotations = 0; 
            } else {
                dq.pop_front();
                dq.push_back(c);
                rotations++;
            }
        }
        return dq.size();
    }
};
