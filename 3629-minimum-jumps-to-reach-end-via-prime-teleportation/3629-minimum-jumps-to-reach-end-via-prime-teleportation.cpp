class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 2;
        for (int x : nums) {
            if (x > max_val) {
                max_val = x;
            }
        }

        vector<int> spf(max_val + 1);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= max_val; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_val; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        vector<int> head(max_val + 1, -1);
        vector<int> nxt;
        vector<int> to;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            while (val > 1) {
                int p = spf[val];
                nxt.push_back(head[p]);
                to.push_back(i);
                head[p] = nxt.size() - 1;
                while (val % p == 0) {
                    val /= p;
                }
            }
        }

        int total_nodes = n + max_val + 1;
        vector<int> dist(total_nodes, 1e9);
        vector<bool> visited(total_nodes, false);
        deque<int> q;

        dist[0] = 0;
        q.push_back(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop_front();

            if (visited[u]) continue;
            visited[u] = true;

            if (u == n - 1) {
                return dist[u];
            }

            if (u < n) {
                // Adjacent steps (weight 1)
                if (u + 1 < n && dist[u + 1] > dist[u] + 1) {
                    dist[u + 1] = dist[u] + 1;
                    q.push_back(u + 1);
                }
                if (u - 1 >= 0 && dist[u - 1] > dist[u] + 1) {
                    dist[u - 1] = dist[u] + 1;
                    q.push_back(u - 1);
                }
                // Teleportation start (weight 1)
                int val = nums[u];
                if (val > 1 && spf[val] == val) {
                    int v = n + val;
                    if (dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        q.push_back(v);
                    }
                }
            } else {
                // Virtual node for prime p = u - n (weight 0)
                int p = u - n;
                for (int e = head[p]; e != -1; e = nxt[e]) {
                    int v = to[e];
                    if (dist[v] > dist[u]) {
                        dist[v] = dist[u];
                        q.push_front(v);
                    }
                }
            }
        }

        return -1;
    }
};