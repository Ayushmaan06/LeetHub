#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n = pos.size();
        vector<tuple<int, int, char, int>> robots(n);
        
        for (int i = 0; i < n; ++i) {
            robots[i] = make_tuple(pos[i], h[i], dir[i], i);
        }

        // Sort the robots based on their positions
        sort(robots.begin(), robots.end());

        stack<int> s;
        vector<bool> survived(n, true);  // Track which robots survive
        for (int i = 0; i < n; i++) {
            int idx = get<3>(robots[i]);
            if (get<2>(robots[i]) == 'R') {
                s.push(i);
            } else {
                while (!s.empty()) {
                    int prevIdx = get<3>(robots[s.top()]);
                    if (h[prevIdx] == h[idx]) {
                        survived[prevIdx] = false;
                        survived[idx] = false;
                        s.pop();
                        break;
                    } else if (h[prevIdx] > h[idx]) {
                        h[prevIdx]--;
                        survived[idx] = false;
                        break;
                    } else {
                        h[idx]--;
                        survived[prevIdx] = false;
                        s.pop();
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (survived[i]) {
                result.push_back(h[i]);
            }
        }

        return result;
    }
};
