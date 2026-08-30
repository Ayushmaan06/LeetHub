class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size(),mini = min_element(nums.begin(), nums.end())-nums.begin(), maxi = max_element(nums.begin(), nums.end())-nums.begin();
        int ans= min({max(mini, maxi)+1, n-min(maxi,mini),min(mini,maxi)+1+(n-max(mini,maxi)) });
        return ans;
    }
};