#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n);
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pos[i] = fruits[i][0];
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }
        
        int ans = 0;
        {
            int leftBound = startPos - k;
            int li = lower_bound(pos.begin(), pos.end(), leftBound) - pos.begin();
            int ri = upper_bound(pos.begin(), pos.end(), startPos) - pos.begin() - 1;
            if (li <= ri)
                ans = max(ans, prefix[ri + 1] - prefix[li]);
        }
        {
            int li = lower_bound(pos.begin(), pos.end(), startPos) - pos.begin();
            int ri = upper_bound(pos.begin(), pos.end(), startPos + k) - pos.begin() - 1;
            if (li <= ri)
                ans = max(ans, prefix[ri + 1] - prefix[li]);
        }
        for (int i = 0; i < n; i++) {
            if (pos[i] > startPos) break;
            int leftCost = startPos - pos[i];
            if (leftCost > k) continue;
            int maxRightBound = k - startPos + 2 * pos[i]; 
            int j = upper_bound(pos.begin(), pos.end(), maxRightBound) - pos.begin() - 1;
            if (j >= i)
                ans = max(ans, prefix[j + 1] - prefix[i]);
        }
        for (int j = n - 1; j >= 0; j--) {
            if (pos[j] < startPos) break;
            int rightCost = pos[j] - startPos;
            if (rightCost > k) continue;
            int minLeftBound = 2 * pos[j] - k - startPos;
            int i_idx = lower_bound(pos.begin(), pos.end(), minLeftBound) - pos.begin();
            if (i_idx <= j)
                ans = max(ans, prefix[j + 1] - prefix[i_idx]);
        }
        
        return ans;
    }
};