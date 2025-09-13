class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        // State contains: [row, column, obstacles eliminated so far, steps taken]
        queue<vector<int>> q;
        q.push({0, 0, 0, 0});
        // 3D visited: visited[i][j][s] = true if cell (i, j) has been visited with s eliminations.
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));
        visited[0][0][0] = true;
        vector<pair<int,int>> dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int i = cur[0], j = cur[1], s = cur[2], steps = cur[3];
            if(i == n-1 && j == m-1)
                return steps;
            for(auto [dr, dc] : dir){
                int rr = i + dr, cc = j + dc;  
                if(rr >= 0 && rr < n && cc >= 0 && cc < m){
                    int ns = s + grid[rr][cc];  
                    if(ns <= k && !visited[rr][cc][ns]){
                        visited[rr][cc][ns] = true;
                        q.push({rr, cc, ns, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};