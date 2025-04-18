class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string k = countAndSay(n - 1); 
        int kk = k.length();
        string res;

        for (int i = 0; i < kk; i++) {
            int j = i;
            while (j + 1 < kk && k[i] == k[j + 1]) {
                j++;
            }
            int c = j - i + 1; 
            i = j; 
            res += to_string(c) + string(1, k[i]);
        }
        
        return res;
    }
};
