class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int ans = 0;
        for(string s : op){
            if(s[0]=='+' || s[s.size()-1]=='+')ans++;
            else ans--;
        }
        return ans;
    }
};