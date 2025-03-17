class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(auto m : mp){
            if(m.second%2)return false;
        }
        return true;
    }
};