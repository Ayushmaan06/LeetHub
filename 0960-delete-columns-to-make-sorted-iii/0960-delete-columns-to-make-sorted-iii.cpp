class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(),m=strs[0].size();
        vector<int> dp(m,1);
        for(int i = 1 ; i < m ; i++){
            for(int j=0 ; j < i ; j++){
                bool ok = true;
                for(string s : strs){
                    if(s[j]>s[i]){ok=false;break;}
                }
                if(ok)dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return m-*max_element(dp.begin(),dp.end());
    }
};