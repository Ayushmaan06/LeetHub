#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_set<string> is;
        unordered_map<string, vector<pair<string, double>>> mp;
        // Build the graph
        for (int i = 0; i < n; i++) {
            string u = eq[i][0], v = eq[i][1];
            mp[u].push_back({v, values[i]});
            mp[v].push_back({u, 1.0 / values[i]});
            is.insert(u); 
            is.insert(v);
        }
        
        vector<double> res;
        // Process each query
        for (vector<string> q : queries) {
            // q[0] is numerator and q[1] is denominator
            string st = q[0], en = q[1];
            if (is.find(st) == is.end() || is.find(en) == is.end()) {
                res.push_back(-1.0);
                continue;
            }
            // Use a BFS/DFS style search with multiplication of weights
            queue<pair<string, double>> qu;
            qu.push({st, 1.0});
            unordered_set<string> visited;
            visited.insert(st);
            bool found = false;
            double ans = -1.0;
            while (!qu.empty() && !found) {
                auto [curr, prod] = qu.front();
                qu.pop();
                if (curr == en) {
                    ans = prod;
                    found = true;
                    break;
                }
                for (auto [next, value] : mp[curr]) {
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        qu.push({next, prod * value});
                    }
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};