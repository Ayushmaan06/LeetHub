class Solution {
public:
    bool isP(int x, int y){
        return (x > 0 && y > 0) || (x < 0 && y < 0);
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int &a : asteroids){
            if(st.empty()){
                st.push(a);
                continue;
            }

            int q = st.top();

            if(isP(a, q) || q < 0 || a > 0) { 
                st.push(a);
            }
            else {
                while(!st.empty() && st.top() > 0 && a < 0 && abs(st.top()) < abs(a)){
                    st.pop();
                }

                if(st.empty()) st.push(a);
                else if(st.top() > 0 && a < 0) {
                    if(abs(st.top()) == abs(a)) st.pop(); 
                } else {
                    st.push(a); 
                }
            }
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
