#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        struct hash_pair {
            size_t operator()(const pair<int, int>& p) const {
                return hash<int>()(p.first * 10 + p.second);  // works because values are [1, 9]
            }
        };

        unordered_map<pair<int, int>, int, hash_pair> mpp;
        int count = 0;
        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            count += mpp[{a, b}]++;
        }
        return count;
    }
};
