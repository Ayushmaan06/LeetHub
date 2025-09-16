class Solution {
public:
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        for (long long n : nums) {
            while (!st.empty() && gcd(n, st.top()) > 1) {
                n = lcm(n, st.top());
                st.pop();
            }
            st.push(n);
        }
        vector<int> res;
        res.reserve(st.size());
        while (!st.empty()) {
            res.emplace_back((int)st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
