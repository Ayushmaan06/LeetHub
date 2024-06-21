class Solution {
public:
    void fillMaxHeight(vector<int>& heights, vector<int>& maxLeft, vector<int>& maxRight) {
        int n = heights.size();
        maxLeft[0] = heights[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i-1], heights[i]);
        }
        
        maxRight[n-1] = heights[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], heights[i]);
        }
    }
    
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int n = height.size();
        vector<int> leftGreater(n), rightGreater(n);
        
        fillMaxHeight(height, leftGreater, rightGreater);
        
        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            int waterLevel = min(leftGreater[i], rightGreater[i]);
            if (waterLevel > height[i]) {
                totalWater += waterLevel - height[i];
            }
        }
        
        return totalWater;
    }
};