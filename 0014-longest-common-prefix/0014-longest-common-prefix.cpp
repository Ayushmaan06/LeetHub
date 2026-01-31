class Solution {
public:
struct Node {
    Node* links[26] = {nullptr};
    int cp = 0; // countPrefix: Number of words passing through this node
    int ce = 0; // countEnd: Number of words ending at this node

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    
    // Destructor to release memory
    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (links[i] != nullptr) {
                delete links[i];
            }
        }
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    ~Trie() {
        delete root;
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->cp++; 
        }
        node->ce++; 
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->ce; 
    }
    int countWordsStartingWith(string &word) {
        Node* node = root;
        for (char ch : word) { 
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->cp; 
    }

    void erase(string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return;
            }
            node = node->get(ch);
            node->cp--; 
        }
        node->ce--; 
    }
    bool search(string word) {
        return countWordsEqualTo(word) > 0;
    }
    bool startsWith(string prefix) {
        return countWordsStartingWith(prefix) > 0;
    }

    string lcp(string s, int n) {
        Node* node = root;
        string r;
        for (char ch : s) {
            if (node->containsKey(ch)) node = node->get(ch);
            else break;
            if (node->cp == n) r += ch;
            else break; 
        }
        return r;
    }
};
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        for(string s : strs)t.insert(s);
        return t.lcp(strs[0], strs.size());
    }
};