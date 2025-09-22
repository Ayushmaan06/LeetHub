class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=-1;
        for(int n : nums)mp[n]++,ans=max(ans,mp[n]);
        int r=0;
        for(auto it : mp)if(it.second == ans)r++;
        return r*ans;
    }
};