class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        unordered_set<char> brokenKeys;
        for (char c : broken) {
            brokenKeys.insert(c);
        }
        
        int count = 0;
        bool brokenWord = false;
        for (int i = 0; i <= text.size(); i++) {
            if (i < text.size() && brokenKeys.count(text[i])) brokenWord = true;
            if (i == text.size() || text[i] == ' ') {
                if (!brokenWord) count++;
                brokenWord = false;
            }
        }
        return count;
    }
};