class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char , int> m;
        int i = 0 , j = 0 , c = 0;
        while(j<s.length()){
            m[s[j]]++;
            while(m.size()==3){
                 c+=(s.length()-j);
                 m[s[i]]--;
                 if(m[s[i]] == 0) {
                     m.erase(s[i]);
                 }
                 i++;
            }
            j++;
        }
        return c;
    }
};