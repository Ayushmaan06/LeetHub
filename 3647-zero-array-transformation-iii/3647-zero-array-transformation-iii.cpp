class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int n = nums.size();
        vector<int> ps(n+1, 0);
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            ps[l]++;             
            if(r + 1 < ps.size()) 
                ps[r+1]--;
        }
        for (int i = 1; i < n; i++) {
            ps[i] += ps[i-1];
        }
        for (int i = 0; i < n; i++) {
            if (ps[i] < nums[i])
                return -1;
        }
        int k = 0;
        vector<int> add(n+1, 0);
        int curr = 0; 
        priority_queue<int> pq; 
        int j = 0; 
        for (int i = 0; i < n; i++) {
            curr += add[i];
            while (curr < nums[i]) {
                while (j < queries.size() && queries[j][0] <= i) {
                    pq.push(queries[j][1]); 
                    j++;
                }
                while (!pq.empty() && pq.top() < i) {
                    pq.pop();
                }
                if (pq.empty())
                    return -1;
                int r = pq.top(); 
                pq.pop();
                k++;     
                curr++;
                add[i]++; 
                if (r+1 < n)
                    add[r+1]--;
            }
        }
        return queries.size() - k;
    }
};