class Solution {
public:
    int nextBeautifulNumber(int n) {
        // vector<int> v;
        if(n>=666666)return 1224444;
        if(n>=555551)return 666666;
        for(int i = n+1 ; i <= 1224444 ; i++){
            string s = to_string(i);
            unordered_map<int,int> mp;
            for(char c : s){
                mp[c-'0']++;
            }
            bool ok=true;
            for(auto &it : mp){
                if(it.first != it.second){ok=false;break;}
            }
            if(ok)return i;
        }
        return 1224444;

    }
};