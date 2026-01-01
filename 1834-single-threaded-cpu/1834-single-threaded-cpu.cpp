class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);   
        }
        sort(tasks.begin(), tasks.end());
        long long t = 0;
        vector<int> res;
        for (int i = 0; i < n; ) {
            t = max(t, (long long)tasks[i][0]);
            res.push_back(tasks[i][2]);
            long long ns = t + tasks[i][1];
            t = ns;
            i++;
            while (i < n && tasks[i][0] <= t) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            while (!pq.empty()) {
                res.push_back(pq.top()[1]);
                t += pq.top()[0];
                pq.pop();

                while (i < n && tasks[i][0] <= t) {
                    pq.push({tasks[i][1], tasks[i][2]});
                    i++;
                }
            }
        }

        return res;
    }
};
