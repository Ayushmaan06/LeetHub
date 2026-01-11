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
            while (!s.empty() && nums[s.top()] >= nums[i]) { // Changed > to >= for consistency
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
            // Simplified width calculation
            // Width = Right Boundary - Left Boundary - 1
            // (right[i]) - (left[i]) - 1
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) dp[0][j] = mat[0][j] - '0';
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1') dp[i][j] = dp[i-1][j] + 1;
            }
        }
        int ans = 0;
        for (vector<int>& v : dp) ans = max(ans, largestRectangleArea(v));
        return ans;
    }
};