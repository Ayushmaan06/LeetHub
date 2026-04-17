class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;int n = nums.size();
        for(int i = 0 ; i < n ; i++)
            mp[nums[i]].push_back(i);
        int ans=INT_MAX,j=0;
        for(int i : nums){
            string s = to_string(i);
            reverse(s.begin(), s.end());
            int k = stoi(s);

            if(mp.find(k) != mp.end()){
                auto it = upper_bound(mp[k].begin(), mp[k].end(), j);
                if(it != mp[k].end()){
                    int x = *it;
                    ans = min(ans, abs(x - j));
                }
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};