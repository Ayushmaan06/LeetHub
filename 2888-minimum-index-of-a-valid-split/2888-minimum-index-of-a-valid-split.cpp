#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int cand = -1, cnt = 0;
        for (int num : nums) {
            if (cnt == 0)
                cand = num;
            cnt += (num == cand) ? 1 : -1;
        }
        int total = 0;
        for (int num : nums) {
            if (num == cand)
                total++;
        }
        if (total * 2 <= n)
            return -1;
        
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == cand)
                leftCount++;
            if (leftCount * 2 > (i + 1) && (total - leftCount) * 2 > (n - i - 1))
                return i;
        }
        
        return -1;
    }
};