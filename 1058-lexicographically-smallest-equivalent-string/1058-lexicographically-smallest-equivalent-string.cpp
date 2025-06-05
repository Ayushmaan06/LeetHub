#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<char, char> parent;
    char find(char c) {
        if (parent[c] != c)
            parent[c] = find(parent[c]);
        return parent[c];
    }
    void unionChars(char a, char b) {
        char rootA = find(a);
        char rootB = find(b);
        if (rootA == rootB) return;

        if (rootA < rootB) {
            parent[rootB] = rootA;
        } else {
            parent[rootA] = rootB;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (char c = 'a'; c <= 'z'; ++c) {
            parent[c] = c;
        }
        for (int i = 0; i < s1.length(); ++i) {
            unionChars(s1[i], s2[i]);
        }
        string result;
        for (char c : baseStr) {
            result += find(c);
        }

        return result;
    }
};
