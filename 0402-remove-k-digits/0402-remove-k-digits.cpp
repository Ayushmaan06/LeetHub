class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == 0) return num;
        if (num.length() <= k) return "0";
        
        string result;
        for (char c : num) {
            while (k > 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        
        // If there are still digits to remove, remove them from the end
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        
        result = result.substr(start);
        
        return result.empty() ? "0" : result;
    }
};
