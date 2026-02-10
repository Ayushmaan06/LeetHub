struct Node {
    Node* links[26] = {nullptr};
    int cp = 0; // countPrefix: Number of words passing through this node
    int ce = 0; // countEnd: Number of words ending at this node

    // Checks if the node contains a link for the given character
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    // Sets a link for the given character to the specified node
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    // Gets the node linked to the given character
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
    // Utility function to count nodes recursively
    int countNodesUtil(Node* node) {
        if (!node) return 0;
        int count = 1;
        for (int i = 0; i < 26; i++) {
            if (node->links[i]) {
                count += countNodesUtil(node->links[i]);
            }
        }
        return count;
    }

public:
    // Constructor: Initializes the trie with a root node
    Trie() {
        root = new Node();
    }
    
    // Destructor: Cleans up the trie memory
    ~Trie() {
        delete root;
    }

    // Inserts a word into the trie
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

    // Counts the number of words equal to the given word
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
    int t=0;
    void ssutil(string &word, int i, Node* n) {
        if (i == word.length()) {if (n->ce > 0) t = 1;return;}

        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (t) return; 
                if (n->links[j] != nullptr) ssutil(word, i + 1, n->links[j]);
            }
        } 
        else {
            char ch = word[i];
            if (n->containsKey(ch)) {
                ssutil(word, i + 1, n->get(ch));
            }
        }
    }
    bool ssearch(string word) {
        t = 0;
        ssutil(word, 0, root);
        return t > 0;
    }
    // Counts the number of words starting with the given prefix
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

    // Erases a word from the trie
    void erase(string &word) {
    if (!search(word)) return; // Always check if word exists first
    Node* node = root;
    for (char ch : word) {
        Node* next = node->get(ch);
        next->cp--;
        // If no more words pass through this node, we could delete it,
        // but that requires a more complex bottom-up recursion.
        // For now, at least ensure cp/ce don't go negative.
        node = next;
    }
    node->ce--;
}

    // Searches for a word in the trie
    bool search(string word) {
        return countWordsEqualTo(word) > 0;
    }

    // Checks if any word starts with the given prefix
    bool startsWith(string prefix) {
        return countWordsStartingWith(prefix) > 0;
    }

    // Finds the longest common prefix with exactly n words
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

    // Utility function for DFS to find the longest word
    void getLongestUtil(string &ans, string &current, Node* node) {
        if (current.length() > ans.length()) ans = current;
        else if (current.length() == ans.length() && current < ans) ans = current;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int index = ch - 'a';
            if (node->links[index] != nullptr && node->links[index]->ce ) {
                current.push_back(ch);
                getLongestUtil(ans, current, node->links[index]);
                current.pop_back(); // Backtrack
            }
        }
    }

    // Finds the longest word in the trie
    string getLongest() {
        string ans = "";
        string current = "";
        // We start DFS from root. Note: Root itself doesn't need to have ce > 0.
        getLongestUtil(ans, current, root);
        
        if (ans == "") return "None"; // Or whatever the problem asks for empty case
        return ans;
    }

    // Counts the total number of nodes in the trie
    int countNodes() {
        return countNodesUtil(root);
    }
};
class WordDictionary {
public:
    Trie t;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        bool f= t.ssearch(word);
        return f;
    }
};
