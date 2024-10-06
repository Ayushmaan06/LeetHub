class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        // If the second sentence is longer, swap the sentences to always compare the smaller one
        if (n1 < n2) {
            swap(words1, words2);
            swap(n1, n2);
        }
        
        int i = 0, j = 0;
        
        // Match from the beginning
        while (i < n2 && words1[i] == words2[i]) {
            i++;
        }
        
        // Match from the end
        while (j < n2 && words1[n1 - 1 - j] == words2[n2 - 1 - j]) {
            j++;
        }
        
        // Ensure that the matched segments cover the entire smaller sentence
        return i + j >= n2;
    }
    
private:
    vector<string> split(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
