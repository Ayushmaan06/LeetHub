class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e7)); // Use a large number to represent infinity

        // Initialize the adjacency matrix
        for (const auto& edge : edges) {
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }

        // Set the diagonal to 0
        for (int i = 0; i < n; ++i) {
            matrix[i][i] = 0;
        }

        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][k] != 1e7 && matrix[k][j] != 1e7) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Count the number of reachable cities within the distance threshold for each city
        vector<int> reachableCitiesCount(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && matrix[i][j] <= distanceThreshold) {
                    ++reachableCitiesCount[i];
                }
            }
        }

        // Find the city with the minimum number of reachable cities within the distance threshold
        // If there's a tie, choose the city with the largest index
        int minCount = n, resultCity = -1;
        for (int i = 0; i < n; ++i) {
            if (reachableCitiesCount[i] <= minCount) {
                minCount = reachableCitiesCount[i];
                resultCity = i;
            }
        }

        return resultCity;
    }
};
