class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        mp['b']=0;mp['a']=0;mp['l']=0;mp['o']=0;mp['n']=0;
        for(char &c : text)
            if(c=='b'||c=='a'||c=='l'||c=='o'||c=='n')mp[c]++;
        int ans = INT_MAX;
        for(auto &it : mp){
            char c = it.first;
            if(c=='b'||c=='a'||c=='n')ans=min(ans,it.second);
            else ans = min(ans,it.second/2);
        }
        return ans;
    }   
};