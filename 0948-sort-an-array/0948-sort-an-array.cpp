class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        sort(nums.begin() , nums.end());
        return nums;
    }
};