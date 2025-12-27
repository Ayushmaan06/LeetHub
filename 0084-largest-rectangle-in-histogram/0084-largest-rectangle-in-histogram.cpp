class Solution {
public:
vector<int> nextSmallerElementLeft(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    
    vector<int> nextSmallerElementRight(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = nextSmallerElementLeft(heights);
        vector<int> right = nextSmallerElementRight(heights);
        int maxArea = 0;
        
        for (int i = 0; i < n; ++i) {
            int leftDist = (left[i] == -1 ? 0 : left[i] + 1);
            int rightDist = (right[i] == n ? n - 1 : right[i] - 1);
            int width = rightDist - leftDist + 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
