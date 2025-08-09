class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int t : nums) {
            pq.push(t);
        }
        int ans = 0;
        while (pq.size() > 1 && pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            long long combined = 2LL * x + y;  // Prevent int overflow
            pq.push(combined);
            ans++;
        }
        if (pq.top() < k) return -1;

        return ans;
    }
};
