class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> ss;
        int n = s.length();
        if(n<k)return false;
        string r;
        for(int i = 0 ; i < k ; i++)r+=s[i];
        ss.insert(r);
        int l=0,h=k;
        while(h<n){
            string x = r.substr(1);
            r=x+s[h];
            h++;
            ss.insert(r);
        }
        return ss.size()==(1<<k);
    }
};