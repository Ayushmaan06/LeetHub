#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        ll ma = *max_element(nums.begin(),nums.end()), mi = *min_element(nums.begin(),nums.end());
        return k*(ma-mi);
    }
};