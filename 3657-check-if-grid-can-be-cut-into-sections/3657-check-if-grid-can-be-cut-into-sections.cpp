class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> rectangle1, rectangle2;
        
        // Extract x and y intervals
        for (auto &rectangle : rectangles) {
            rectangle1.push_back({rectangle[0], rectangle[2]});
            rectangle2.push_back({rectangle[1], rectangle[3]});
        }
        
        // Sort the intervals based on their starting points
        sort(rectangle1.begin(), rectangle1.end());
        sort(rectangle2.begin(), rectangle2.end());
        
        // Process the x intervals
        int end1 = rectangle1[0][1], count1 = 0;
        int end2 = rectangle2[0][1], count2 = 0;

        for (int i = 1; i < rectangles.size(); i++) {
            if (rectangle1[i][0] < end1) {
                end1 = max(rectangle1[i][1], end1);
            } else {
                count1++;
                end1 = rectangle1[i][1];
            }

            if (rectangle2[i][0] < end2) {
                end2 = max(rectangle2[i][1], end2);
            } else {
                count2++;
                end2 = rectangle2[i][1];
            }

            // If either count exceeds 1, we found more than one required partition
            if (count1 == 2 || count2 == 2) return true;
        }
        
        return false;
    }
};