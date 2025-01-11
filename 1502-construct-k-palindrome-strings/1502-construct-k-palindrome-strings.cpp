class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) return false;  
        
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        
        int oddCount = 0;
        for (auto& it : m) {
            if (it.second % 2 != 0) {
                oddCount++;  
            }
        }

        return oddCount <= k;
    }
};
