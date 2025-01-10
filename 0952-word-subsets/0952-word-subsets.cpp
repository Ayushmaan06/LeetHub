
class Solution {
public:

    unordered_map<char, int> countFrequency(const string& word) {
        unordered_map<char, int> count;
        for (char ch : word) {
            count[ch]++;
        }
        return count;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> superCount;
        for (const string& word : words2) {
            unordered_map<char, int> wordCount = countFrequency(word);
            for (const auto& [ch, freq] : wordCount) {
                superCount[ch] = max(superCount[ch], freq);
            }
        }

        vector<string> ans;

        for (const string& word : words1) {
            unordered_map<char, int> wordCount = countFrequency(word);
            bool isValid = true;
            
            for (const auto& [ch, requiredFreq] : superCount) {
                if (wordCount[ch] < requiredFreq) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
