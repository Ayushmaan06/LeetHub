class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> m,mm;
        for(int i : nums)m[i]++;
        for(auto it : m)mm[it.second]++;
        for(int i : nums)if(mm[m[i]]==1)return i;
        return -1;
    }
};