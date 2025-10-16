class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i = 0 ; i < n ; i++){
            int r = ((nums[i] % value) + value) % value;
            mp[r]++;
            v.push_back(r + mp[r]*value - value);
        }
        sort(v.begin(),v.end());
        for(int i = 0 ; i < n ; i++){
            if(i!=v[i])return i;
        }
        return n;
    }
};
