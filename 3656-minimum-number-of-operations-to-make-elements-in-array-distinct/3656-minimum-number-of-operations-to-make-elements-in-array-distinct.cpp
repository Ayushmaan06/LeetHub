class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool vis[101] = {false};
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (vis[nums[i]]) {
                return i / 3 + 1;
            }
            vis[nums[i]] = true;
        }
        return 0;
    }
};