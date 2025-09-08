class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i =1;i<n;i++){
            string s = to_string(i), s1 = to_string(n-i);
            sort(s.begin(),s.end());
            sort(s1.begin(),s1.end());
            if(s[0]!='0' && s1[0]!='0')return {i,n-i};
        }
        return {-1};
    }
};