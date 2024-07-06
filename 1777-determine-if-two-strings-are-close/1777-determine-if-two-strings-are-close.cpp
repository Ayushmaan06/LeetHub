
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;

        unordered_map<char, int> freq1, freq2;
        for (char c : word1) freq1[c]++;
        for (char c : word2) freq2[c]++;

        if (freq1.size() != freq2.size()) return false;

        for (auto& p : freq1) {
            if (freq2.find(p.first) == freq2.end()) return false;
        }

        vector<int> freqList1, freqList2;
        for (auto& p : freq1) freqList1.push_back(p.second);
        for (auto& p : freq2) freqList2.push_back(p.second);

        sort(freqList1.begin(), freqList1.end());
        sort(freqList2.begin(), freqList2.end());

        return freqList1 == freqList2;
    }
};