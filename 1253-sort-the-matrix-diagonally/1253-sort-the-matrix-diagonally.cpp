class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        int n = grid.size(),m= grid[0].size();
        for(int i =0 ; i < n-1 ; i++){
            int sr=i,sc=0;
            vector<int> temp;
            while(sr<n && sc<m){
                temp.push_back(grid[sr][sc]);
                sr++;sc++;
            }
            sort(temp.begin(),temp.end());
            sr=i,sc=0;
            int x= 0;
            while(sr<n && sc<m) grid[sr++][sc++] = temp[x++];
        }
        for(int i = 1 ; i < m-1 ; i++){
            int sr=0,sc=i;
            vector<int> temp;
            while(sr<n && sc<m){
                temp.push_back(grid[sr][sc]);
                sr++;sc++;
            }
            sort(temp.begin(),temp.end());
            sr=0,sc=i;
            int x= 0;
            while(sr<n && sc<m) grid[sr++][sc++] = temp[x++];
        }
        return grid;
    }
};