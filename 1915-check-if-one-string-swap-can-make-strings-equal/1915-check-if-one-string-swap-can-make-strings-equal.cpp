class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        unordered_map<char,int> mp;
        for(char c : s1)mp[c]++;
        for(char c : s2){
            mp[c]--;
            if(mp[c]==0)mp.erase(c);
        }
        if(!mp.empty())return false;
        int n1=s1.length(),n2=s2.length();
        if(n1!=n2)return false;
        int n = n1,c=0;
        for(int i = 0 ; i < n ; i++){
            if(s1[i]!=s2[i])c++;
        }
        return c<3;
    }
};