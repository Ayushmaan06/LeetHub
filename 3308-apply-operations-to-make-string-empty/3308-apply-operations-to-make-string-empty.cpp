class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> v(26,0);
        int ma = INT_MIN;
        for (char c : s) {
            v[c-'a']++;
            ma = max(ma, v[c-'a']);
        }
        for(int i =0 ; i < 26 ; i++){
            if(v[i]){
                v[i]-=ma;
                v[i]++;
                if(v[i]<0)v[i]=0;
            }
        }
        int n = s.length();
        string res = "";
        for (int i = n - 1; i >= 0; i--) {
            if (v[s[i]-'a'] > 0) {
                v[s[i]-'a']--;
                res += s[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
