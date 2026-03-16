class Solution {
public:
    int characterReplacement(string s, int k) {
        int i =0 , j = 0;
        unordered_map<char,int> mp;
        int n = s.length(),mx=-1,ans=-1;
        char mc;
        while(j<n){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            if(mp[s[j]]==mx)mc=s[j];
            while(j-i+1-mx>k){
                mp[s[i]]--;
                // if(s[i]==mc)mx--;
                // mx=max(mx,mp[s[i]]);
                // // if(mp[s[i]]==mx)mc=s[j];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};