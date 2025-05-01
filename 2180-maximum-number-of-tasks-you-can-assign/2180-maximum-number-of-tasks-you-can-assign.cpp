class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());
        int usedPills = 0;
        for (int i = k - 1; i >= 0; --i) {
            auto it = available.lower_bound(tasks[i]);
            if (it != available.end()) {
                available.erase(it);
            } 
            else {
                auto it2 = available.lower_bound(tasks[i] - strength);
                if (it2 == available.end()) return false;
                available.erase(it2);
                usedPills++;
                if (usedPills > pills) return false;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0, high = min(tasks.size(), workers.size()), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};