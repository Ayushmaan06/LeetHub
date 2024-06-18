class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> r;
        for(int i = 0 ; i < (1<<(nums.size())); i++){
            vector<int> v;
            for(int j = 0 ; j < nums.size() ; j++){
                if(i&(1<<j)){
                    v.push_back(nums[j]);
                }
                sort(v.begin() , v.end());
                if(find(r.begin() , r.end() ,v)==r.end()){
                    r.push_back(v);
                }
            }
        }
        return r;
    }
};