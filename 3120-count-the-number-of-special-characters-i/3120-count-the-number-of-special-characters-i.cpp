class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<char> v(52,0);
        for(char c : word){
            if(c>='a' && c<='z')v[c-'a']++;
            else v[26 + (c-'A')]++;
        }
        int i = 0 , j = 0;
        while(i<26){
            if(v[i] && v[i+26])j++;
            i++;
        }
        return j;
    }
};