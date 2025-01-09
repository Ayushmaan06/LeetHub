class Solution {
public:
    bool ip(string s1, string s2, int n){
        for(int i = 0 ; i < n ; i++){
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int n = pref.length();
        for(string word : words){
            if(word.length()>=n){
                if(ip(pref,word,n))ans++;
            }
        }
        return ans;
    }
};