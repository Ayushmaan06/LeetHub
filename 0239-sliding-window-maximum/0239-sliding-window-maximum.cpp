class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // Max-heap to store pairs of (value, index)
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Push the current element along with its index onto the heap
            pq.push({nums[i], i});

            // Remove elements that are out of the current window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // Record the maximum for the current window
            if (i >= k - 1) {
                result.push_back(pq.top().first);
            }
        }

        return result;
    }
};
