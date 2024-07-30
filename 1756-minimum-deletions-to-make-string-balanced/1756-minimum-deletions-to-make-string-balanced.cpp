class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int b_count = 0;
        int min_deletions = 0;
        
        for (char c : s) {
            if (c == 'b') {
                b_count++;
            } else {
                // For every 'a', we have two choices:
                // 1. Delete this 'a' (min_deletions++)
                // 2. Delete all previous 'b's seen so far
                // We take the minimum of these two choices
                min_deletions = min(min_deletions + 1, b_count);
            }
        }
        
        return min_deletions;
    }
};
