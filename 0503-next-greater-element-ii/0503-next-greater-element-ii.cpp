class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nextGreater(n, -1); // Initialize result vector with -1
    stack<int> s; // Use stack to keep track of elements

    // Iterate twice over the array to handle circular nature
    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n]; // Circular indexing

        // Pop elements from the stack smaller than the current element
        while (!s.empty() && nums[s.top()] < num) {
            nextGreater[s.top()] = num; // Update next greater element for the popped index
            s.pop();
        }

        // In the first pass, push the index onto the stack
        if (i < n) s.push(i);
    }

    return nextGreater;
}
};