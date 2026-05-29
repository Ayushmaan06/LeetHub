class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i : nums){
            string s = to_string(i);
            int x =0;
            for(char c : s){
                x+=(c-'0');
            }
            ans=min(ans,x);
        }
        return ans;
    }
};