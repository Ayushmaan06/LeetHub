class Solution {
public:
    bool diff1(const string &s1, const string &s2) {
        int diffCount = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) diffCount++;
            if (diffCount > 1) return false;
        }
        return diffCount == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;  
        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                if (current == endWord) return level;

                for (auto it = wordSet.begin(); it != wordSet.end();) {
                    if (diff1(current, *it)) {
                        q.push(*it);
                        it = wordSet.erase(it); 
                    } else {
                        ++it;
                    }
                }
            }
            level++;
        }

        return 0;
    }
};
