class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> rank;
    for (int i = 0; i < order.size(); i++)
        rank[order[i]] = i;

    for (int i = 0; i < words.size() - 1; i++) {
        string &w1 = words[i], &w2 = words[i + 1];
        int len = min(w1.size(), w2.size());
        bool diffFound = false;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                if (rank[w1[j]] > rank[w2[j]])
                    return false;
                diffFound = true;
                break;
            }
        }

        if (!diffFound && w1.size() > w2.size())
            return false;
    }
    return true;
}

};