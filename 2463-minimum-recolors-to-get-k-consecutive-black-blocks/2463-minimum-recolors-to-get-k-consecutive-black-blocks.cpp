class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0, n = blocks.length(), ans = INT_MAX, count = 0;
        
        while (r < n) {
            if (blocks[r] == 'B') {
                count++;
            }
            if (r - l + 1 == k) {
                ans = min(ans, k - count);
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
