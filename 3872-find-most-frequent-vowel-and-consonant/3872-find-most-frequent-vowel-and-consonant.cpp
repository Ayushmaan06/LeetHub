class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int maxVowel = 0, maxConsonant = 0;
        int vowels[5] = {0, 4, 8, 14, 20};
        for (int i = 0; i < 5; i++) {
            maxVowel = max(maxVowel, freq[vowels[i]]);
        }
        for (int i = 0; i < 26; i++) {
            bool isVowel = false;
            for (int j = 0; j < 5; j++) {
                if (i == vowels[j]) {
                    isVowel = true;
                    break;
                }
            }
            if (!isVowel) {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }
        
        return maxVowel + maxConsonant;
    
    }
};