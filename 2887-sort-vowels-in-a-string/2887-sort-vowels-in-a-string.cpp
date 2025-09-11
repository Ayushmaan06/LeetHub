class Solution {
public:
    bool isV(char c){
        return(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    string sortVowels(string s) {
        vector<char> v;
        for(int i = 0 ; i < s.length() ; i++){
            if(isV(s[i])){
                v.push_back(s[i]);
            }
        }
        sort(v.begin(), v.end());
        string r;int j = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(isV(s[i])){
                r+=v[j++];
            }
            else
                r+=s[i];
        }
        return r;
    }
};