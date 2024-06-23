#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isC, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isC.size(); j++) {
            if (isC[i][j] == 1 && !visited[j]) {
                dfs(isC, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isC) {
        int n = isC.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isC, visited, i);
                count++;
            }
        }
        return count;
    }
};