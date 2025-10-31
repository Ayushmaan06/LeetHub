class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> res;
        for(int i = 0 ; i < n ; i++){
            bool f=true;
            while(i!=nums[i]){
                if(nums[nums[i]]==nums[i]){res.insert(nums[i]);break;}
                swap(nums[nums[i]],nums[i]);
            }

        }
        vector<int> v (res.begin(),res.end());
        return v;
    }
};