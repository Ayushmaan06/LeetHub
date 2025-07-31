class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size(),1);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]%2 != nums[i-1]%2){
                prefix[i] = prefix[i-1]+1;
            }
        }
        vector<bool> ans;
        for(int i = 0; i < queries.size(); i++){
            int s = queries[i][0];
            int e = queries[i][1];
            if(prefix[e]-prefix[s] == e-s){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};