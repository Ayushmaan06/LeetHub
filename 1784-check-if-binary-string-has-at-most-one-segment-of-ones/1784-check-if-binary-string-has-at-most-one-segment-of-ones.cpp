class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length(),i=0;
        while(i<n && s[i]=='1')i++;
        if(i==n)return true;
        while(i<n && s[i]=='0')i++;
        if(i==n)return true;
        return false;
    }
};