class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());  // Sort intervals by start time
        
        int busy_days = 0;
        int last_end = 0;
        
        for (auto &m : meetings) {
            int start = max(last_end + 1, m[0]); // Avoid counting overlapping parts
            int end = m[1];

            if (start <= end) {
                busy_days += (end - start + 1);
                last_end = end;
            }
        }
        
        return days - busy_days;
    }
};
