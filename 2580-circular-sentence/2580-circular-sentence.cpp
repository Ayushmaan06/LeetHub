class Solution {
public:
    vector<string> splitSentenceIntoWords(const string &sentence) {
        vector<string> words;
        istringstream stream(sentence);
        string word;
        
        while (stream >> word) {
            words.push_back(word);
        }
        
        return words;
    }
    bool isCircularSentence(string sentence) {
        vector<string> words = splitSentenceIntoWords(sentence);
        int k = words[0].length();
        char p = words[0][k-1];
        for(int i = 1; i < words.size() ; i++){
            int q = words[i].length();
            if(p!=words[i][0])return false;
            p=words[i][q-1];
        }
        if(p==words[0][0])return true;
        return false;
    }
};