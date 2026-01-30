#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const long long INF = 1e14; // Larger than any possible sum of costs

class TrieNode {
public:
    TrieNode* children[26];
    int id;

    TrieNode() {
        id = -1;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Solution {
    TrieNode* root;
    int idCounter;

    // Helper to insert into Trie and get/assign ID
    int getID(const string& s) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        if (node->id == -1) {
            node->id = idCounter++;
        }
        return node->id;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        root = new TrieNode();
        idCounter = 0;

        // 1. Map all substrings to unique IDs
        // We only care about substrings that appear in our rules
        for (const string& s : original) getID(s);
        for (const string& s : changed) getID(s);

        int n = idCounter;
        
        // 2. Build the graph and compute APSP (Floyd-Warshall)
        vector<vector<long long>> dist(n, vector<long long>(n, INF));
        for (int i = 0; i < n; ++i) dist[i][i] = 0;

        for (int i = 0; i < original.size(); ++i) {
            int u = getID(original[i]);
            int v = getID(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == INF) continue; // Optimization
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int len = source.length();
        vector<long long> dp(len + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < len; ++i) {
            if (dp[i] == INF) continue;
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            TrieNode* p1 = root; 
            TrieNode* p2 = root; 
            for (int j = i; j < len; ++j) {
                int charSrc = source[j] - 'a';
                int charTgt = target[j] - 'a';
                if (!p1->children[charSrc]) break; 
                if (!p2->children[charTgt]) break; 
                p1 = p1->children[charSrc];
                p2 = p2->children[charTgt];
                if (p1->id != -1 && p2->id != -1) {
                    if (dist[p1->id][p2->id] != INF) {
                        dp[j + 1] = min(dp[j + 1], dp[i] + dist[p1->id][p2->id]);
                    }
                }
            }
        }

        return (dp[len] == INF) ? -1 : dp[len];
    }
};