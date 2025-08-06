class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26,0);
        for(char c : s){
            v[c-'a']++;
        }
        string res="";
        for(char o : order){
            int n = v[o-'a'];
            v[o-'a']=0;
            for(int i = 0 ; i < n ; i++){
                res+=o;
            }
        }
        for(char c : s){
            if(v[c-'a'])res+=c;
        }
        return res;
    }
};