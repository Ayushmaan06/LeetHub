class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length(),b = 0,mi = 0;
        for (char c : s) {
            if (c == 'b') b++;
            else mi = min(mi + 1, b);
        }
        return mi;
    }
};
