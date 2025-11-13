class Solution {
public:
    int maxOperations(string s) {
        int ans=0,o=0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i]=='0'){
                ans+=o;
                while(i+1 < s.length() && s[i+1]=='0')i++;
            }
            else o++;
        }
        return ans;
    }
};