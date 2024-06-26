

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (wordSet.find(endWord) == wordSet.end()) return result; // End word not in word list

        unordered_map<string, vector<string>> predecessors;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> localVisited;
            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();
                string original = current;
                for (int j = 0; j < current.size(); ++j) {
                    char originalChar = current[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        current[j] = c;
                        if (wordSet.find(current) != wordSet.end()) {
                            if (current == endWord) {
                                found = true;
                                predecessors[current].push_back(original);
                            } else if (visited.find(current) == visited.end()) {
                                if (localVisited.find(current) == localVisited.end()) {
                                    q.push(current);
                                    localVisited.insert(current);
                                }
                                predecessors[current].push_back(original);
                            }
                        }
                    }
                    current[j] = originalChar; // Restore the original character
                }
            }
            for (const auto& word : localVisited) {
                visited.insert(word);
            }
        }

        if (found) {
            vector<string> path;
            dfs(endWord, beginWord, predecessors, path, result);
        }

        return result;
    }

private:
    void dfs(const string& word, const string& beginWord, unordered_map<string, vector<string>>& predecessors,
             vector<string>& path, vector<vector<string>>& result) {
        path.push_back(word);
        if (word == beginWord) {
            vector<string> tempPath = path;
            reverse(tempPath.begin(), tempPath.end());
            result.push_back(tempPath);
        } else {
            for (const string& pred : predecessors[word]) {
                dfs(pred, beginWord, predecessors, path, result);
            }
        }
        path.pop_back();
    }
};
