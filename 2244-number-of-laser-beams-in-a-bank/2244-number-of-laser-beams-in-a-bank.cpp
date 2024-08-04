class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev_count = 0;
        int total_beams = 0;

        for (const string& row : bank) {
            int current_count = count(row.begin(), row.end(), '1');
            if (current_count > 0) {
                total_beams += prev_count * current_count;
                prev_count = current_count;
            }
        }

        return total_beams;
    }
};