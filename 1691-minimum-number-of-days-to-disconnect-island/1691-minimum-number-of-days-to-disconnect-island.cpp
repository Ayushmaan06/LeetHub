#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        UnionFind uf(rows * cols);
        int numWaterCells = 0;

        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    for (auto& dir : directions) {
                        int nr = r + dir.first;
                        int nc = c + dir.second;
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                            uf.unionSets(r * cols + c, nr * cols + nc);
                        }
                    }
                } else {
                    numWaterCells++;
                }
            }
        }

        // Count unique roots
        int numIslands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1 && uf.find(r * cols + c) == r * cols + c) {
                    numIslands++;
                }
            }
        }

        if (numIslands > 1 || numIslands == 0) return 0;
        

        // Check if removing one land cell can lead to multiple islands
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    grid[r][c] = 0;
                    if (countIslands(grid) > 1 || countIslands(grid)==0 ) {
                        return 1;
                    }
                    grid[r][c] = 1;
                }
            }
        }

        return 2;
    }

private:
    int countIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        UnionFind uf(rows * cols);

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    for (auto& dir : directions) {
                        int nr = r + dir.first;
                        int nc = c + dir.second;
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                            uf.unionSets(r * cols + c, nr * cols + nc);
                        }
                    }
                }
            }
        }

        int numIslands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1 && uf.find(r * cols + c) == r * cols + c) {
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};