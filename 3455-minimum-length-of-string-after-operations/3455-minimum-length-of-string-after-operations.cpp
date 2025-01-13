class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m;
        for(char c: s){
            m[c]++;
        }
        int ans=0;
        for(auto it : m){
            if(it.second > 2){
                if(it.second % 2)ans++;
                else{
                    ans+=2;
                }
            }
            else{
                ans+=it.second;
            }
        }
        return ans;
    }
};