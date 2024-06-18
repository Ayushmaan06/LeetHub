class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Step 1: Create pairs of (difficulty, profit) and sort them by difficulty
        vector<pair<int, int>> tasks;
        for (int i = 0; i < difficulty.size(); ++i) {
            tasks.emplace_back(difficulty[i], profit[i]);
        }
        sort(tasks.begin(), tasks.end());

        // Step 2: Sort the worker array
        sort(worker.begin(), worker.end());

        // Step 3: Iterate over workers and find the maximum profit
        int maxProfit = 0, totalProfit = 0;
        int taskIndex = 0;

        for (int w : worker) {
            // Move the task index to the right while the worker can handle the difficulty
            while (taskIndex < tasks.size() && w >= tasks[taskIndex].first) {
                maxProfit = max(maxProfit, tasks[taskIndex].second);
                ++taskIndex;
            }
            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};
