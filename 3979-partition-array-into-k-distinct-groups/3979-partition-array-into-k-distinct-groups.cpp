class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k>0)return false;
        int g = n/k;
        unordered_map<int,int> mp;
        for(int nn : nums){
            mp[nn]++;
            if(mp[nn]>g)return false;
        }
        return true;
    }
};