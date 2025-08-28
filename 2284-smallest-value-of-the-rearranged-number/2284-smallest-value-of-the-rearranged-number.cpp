class Solution {
public:
    long long smallestNumber(long long num) {
        if (num < 0) {
            num = -num;
            string s = to_string(num);
            sort(s.rbegin(), s.rend());   
            return -stoll(s);             
        }
        string s = to_string(num);
        sort(s.begin(), s.end());
        int i = 0;
        while (i < (int)s.size() && s[i] == '0') i++;
        if (i < (int)s.size()) swap(s[0], s[i]);             
        return stoll(s);
    }
};
