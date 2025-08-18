class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n, 0);
        vector<int> outDegree(n, 0);
        
        for (auto& t : trust) {
            int u = t[0] - 1;
            int v = t[1] - 1;
            outDegree[u]++;
            inDegree[v]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i + 1; 
            }
        }
        
        return -1; // No judge found
    }
};
