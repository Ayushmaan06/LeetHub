class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,r = height.size() - 1,ma = 0; 
        while (l < r) {
            int w = r-l, ch =min(height[l], height[r]);
            int ca = w * ch;
            ma = max(ma, ca);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ma;
    }
};