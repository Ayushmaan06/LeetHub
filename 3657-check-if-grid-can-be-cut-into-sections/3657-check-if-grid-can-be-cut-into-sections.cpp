#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> x, y, xx, yy;
        for(auto& r : rectangles){
            x.push_back({r[0], r[2]});
            y.push_back({r[1], r[3]});
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for (int i = 0; i < x.size(); i++) {
            int st = x[i].first, en = x[i].second;
            while(i + 1 < x.size() && (x[i+1].first < en)) {
                en = max(en, x[i+1].second);
                i++;
            }
            xx.push_back({st, en});
        }
        for (int i = 0; i < y.size(); i++) {
            int st = y[i].first, en = y[i].second;
            while(i + 1 < y.size() && (y[i+1].first < en)) {
                en = max(en, y[i+1].second);
                i++;
            }
            yy.push_back({st, en});
        }
        return (xx.size() > 2 || yy.size() > 2);
    }
};