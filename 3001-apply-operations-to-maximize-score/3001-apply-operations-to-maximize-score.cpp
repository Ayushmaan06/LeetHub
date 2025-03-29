#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
 
// Sieve to compute smallest prime factor (spf) for numbers up to maxN
vector<int> computeSPF(int maxN) {
    vector<int> spf(maxN + 1);
    for (int i = 0; i <= maxN; i++)
        spf[i] = i;
    for (int i = 2; i * i <= maxN; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= maxN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
    return spf;
}
 
// Compute the prime score of n (the number of distinct prime factors)
int primeScore(int n, const vector<int>& spf) {
    int count = 0;
    int prev = -1;
    while(n > 1) {
        int factor = spf[n];
        if (factor != prev) {
            count++;
            prev = factor;
        }
        n /= factor;
    }
    return count;
}
 
// Fast modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxN = 100000;
        vector<int> spf = computeSPF(maxN);
 
        vector<int> pScore(n);
        for (int i = 0; i < n; i++) {
            pScore[i] = primeScore(nums[i], spf);
        }
        vector<int> left(n), right(n);
 
        {
            stack<int> st;
            for (int i = 0; i < n; i++) {
                while(!st.empty() && pScore[st.top()] < pScore[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    left[i] = -1;
                } else {

                    left[i] = st.top();
                }
                st.push(i);
            }
        }

        {
            while(!stack<int>().empty()){}
            stack<int> st;
            for (int i = n - 1; i >= 0; i--) {
                while(!st.empty() && pScore[st.top()] <= pScore[i]) {
                    st.pop();
                }
                if(st.empty())
                    right[i] = n;
                else
                    right[i] = st.top();
                st.push(i);
            }
        }
 
        vector<long long> countSub(n);
        for (int i = 0; i < n; i++) {
            long long leftCount = i - (left[i] == -1 ? -1 : left[i]);
            long long rightCount = right[i] - i;
            countSub[i] = leftCount * rightCount;
        }

        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });
 
        long long ans = 1;
        long long remaining = k;
        for (int i : indices) {
            if (remaining <= 0)
                break;
            long long ops = min(remaining, countSub[i]);
            ans = (ans * modPow(nums[i], ops, MOD)) % MOD;
            remaining -= ops;
        }
 
        return (int)ans;
    }
};
 
#ifdef DEBUG
int main(){
    Solution sol;
    vector<int> nums = {3289,2832,14858,22011};
    int k = 6;
    cout << sol.maximumScore(nums, k) << endl; 
    return 0;
}
#endif