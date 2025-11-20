class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1])
            return a[1] < b[1];
        return a[0] > b[0];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int count = 0;
        int p1 = -1,p2 = -1; 
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            bool p1_in = (start <= p1 && p1 <= end); // Is p1 inside?
            bool p2_in = (start <= p2 && p2 <= end); // Is p2 inside?
            
            if (p1_in && p2_in) {
                continue;
            }
            else if (p1_in) {
                p2 = p1;
                p1 = end; 
                count++;
            }
            else {
                p2 = end - 1;
                p1 = end;
                count += 2;
            }
        }
        
        return count;
    }
};