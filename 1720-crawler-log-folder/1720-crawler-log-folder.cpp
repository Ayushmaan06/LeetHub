#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        string c = "./", p = "../";
        int t = 0;
        for (string l : logs) {
            if (l == c) continue;
            if (l == p) {
                if (t > 0) t--;
            } else {
                t++;
            }
        }
        return t;
    }
};
