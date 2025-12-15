class Solution {
public:
    int maxProfit(vector<int>& v) {
        int min=v[0],ans=0;
        int n = v.size();
        for(int i = 0 ; i < n ; i++){
            if(v[i]>min) ans=max(ans,v[i]-min);
            else min=v[i];
        }
        return ans;
    }
};