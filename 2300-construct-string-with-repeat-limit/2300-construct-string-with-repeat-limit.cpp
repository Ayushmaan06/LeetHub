class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        map<char, int> m;
        
        for (char c : s) {
            m[c]++;
        }
        
        while (!m.empty()) {
            auto it = m.rbegin(); 
            int k = repeatLimit;
            
            // Add the character up to repeatLimit times
            while (k > 0 && it->second > 0) {
                res += it->first;
                it->second--;
                k--;
            }
            
            // If the character still has remaining frequency
            if (it->second > 0) {
                // Find the next highest character
                auto it1 = next(it);
                if (it1 != m.rend()) {
                    res += it1->first;
                    it1->second--;
                    if (it1->second == 0) {
                        m.erase(it1->first);
                    }
                } else {
                    break; // No more characters to add
                }
            }
            
            // Remove the character if its frequency is zero
            if (it->second == 0) {
                m.erase(it->first);
            }
        }
        
        return res;
    }
};