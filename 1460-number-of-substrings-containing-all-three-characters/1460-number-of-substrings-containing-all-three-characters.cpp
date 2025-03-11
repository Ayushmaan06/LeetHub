class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3,-1);
        int i = 0 , j = 0 , c = 0;
        while(j<s.length()){
            v[s[j]-'a']=j;
            int mini = INT_MAX;
            for(int m : v)mini=min(mini,m);
            c+=mini+1;
            j++;
        }
        return c;
    }
};