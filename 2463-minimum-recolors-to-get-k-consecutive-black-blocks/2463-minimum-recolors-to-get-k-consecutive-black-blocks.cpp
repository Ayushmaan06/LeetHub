class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0, n = blocks.length(), ans = INT_MAX, count = 0;
        
        // Slide the window and maintain the count of 'B' in the current window.
        while (r < n) {
            // Add the current block to the window
            if (blocks[r] == 'B') {
                count++;
            }
            
            // When we have a full window of size k, calculate the result
            if (r - l + 1 == k) {
                // Update the answer by the number of 'B's in the current window
                ans = min(ans, k - count);
                
                // Slide the window, remove the leftmost element from the window
                if (blocks[l] == 'B') {
                    count--;
                }
                l++;
            }
            r++;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};
