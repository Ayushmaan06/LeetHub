class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(int n : nums){
            while(!st.empty() && gcd(n,st.top())>1){
                int x = st.top();st.pop();
                n=lcm(n,x);
            }
            st.push(n);
        }
        vector<int> res;
        while(!st.empty())res.push_back(st.top()),st.pop();
        reverse(res.begin(),res.end());
        return res;
    }
};