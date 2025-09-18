class Solution {
public:
    int minPartitions(string n) {
        char ans = '0';
        for (char& u : n) ans = max(ans, u);
        return ans - '0';
    }
};