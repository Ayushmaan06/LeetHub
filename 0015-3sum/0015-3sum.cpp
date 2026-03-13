class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        set<vector<int>> res;

        for(int i = 0 ; i < n ; i++) mp[nums[i]] = i;

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int s = nums[i] + nums[j];
                if(mp.find(-s) != mp.end()){
                    int w = mp[-s];
                    if(w > j){
                        vector<int> temp = {nums[i], nums[j], nums[w]};
                        sort(temp.begin(), temp.end());
                        res.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};