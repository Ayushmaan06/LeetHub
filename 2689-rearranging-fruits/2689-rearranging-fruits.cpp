#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp, b1, b2;
        for (int& b : basket1) {
            mp[b]++;
            b1[b]++;
        }
        for (int& b : basket2) {
            mp[b]++;
            b2[b]++;
        }
        vector<int> g1, g2;
        for (auto &p : mp) {
            int fruit = p.first;
            int tot = p.second;
            if (tot % 2 != 0)
                return -1;
            int cnt1 = b1[fruit];
            int cnt2 = b2[fruit];
            int diff = abs(cnt1 - cnt2) / 2;
            if (cnt1 > cnt2) {
                for (int i = 0; i < diff; i++)
                    g1.push_back(fruit);
            } else if (cnt2 > cnt1) {
                for (int i = 0; i < diff; i++)
                    g2.push_back(fruit);
            }
        }
        sort(g1.begin(), g1.end());
        sort(g2.rbegin(), g2.rend());
        if (g1.size() != g2.size()) return -1;
        long long ans = 0;
        int globalMin = min(*min_element(basket1.begin(), basket1.end()),
                            *min_element(basket2.begin(), basket2.end()));
        for (int i = 0; i < g1.size(); i++) {
            ans += min(min(g1[i], g2[i]), 2 * globalMin);
        }
        return ans;
    }
};