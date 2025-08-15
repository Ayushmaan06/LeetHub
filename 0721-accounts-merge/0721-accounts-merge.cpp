#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;  // For union by rank
    vector<int> size;  // For union by size

public:
    // Constructor: initialize DSU with n elements (0-indexed)
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Path compression find
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    // Union by rank: attach tree with lower rank under tree with higher rank
    void unionByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }

    // Union by size: attach tree with smaller size under tree with larger size
    void unionBySize(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;     
        unordered_map<int, string> name;      
        int x = 0;
        unordered_set<string> us; 
        for (auto &acc : accounts) {
            for (int i = 1; i < acc.size(); i++) {
                if (mp.find(acc[i]) == mp.end()) {
                    mp[acc[i]] = x;
                    name[x] = acc[0];
                    x++;
                }
                us.insert(acc[i]);
            }
        }
        DSU dsu(x);
        for (auto &acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                dsu.unionByRank(mp[acc[i]], mp[acc[i-1]]);
            }
        }
        
        //YAHA SE GPT BHAU NE HELP KRI THI THORI SI
        // Collect emails belonging to the same component.
        unordered_map<int, vector<string>> groups;
        for (auto email : us) {
            int parentIndex = dsu.find(mp[email]);
            groups[parentIndex].push_back(email);
        }
        
        // Prepare final result by sorting emails and prepending the name.
        vector<vector<string>> res;
        for (auto &entry : groups) {
            vector<string> emails = entry.second;
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(name[entry.first]);
            account.insert(account.end(), emails.begin(), emails.end());
            res.push_back(account);
        }
        
        return res;
    }
};