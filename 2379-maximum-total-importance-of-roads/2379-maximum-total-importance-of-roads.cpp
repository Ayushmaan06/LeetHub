class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        // Count the degree of each city
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        // Sort cities by degree in descending order
        vector<pair<int, int>> cityDegree;
        for (int i = 0; i < n; ++i) {
            cityDegree.emplace_back(degree[i], i);
        }
        sort(cityDegree.rbegin(), cityDegree.rend());

        // Assign values to cities based on sorted order
        vector<int> value(n);
        for (int i = 0; i < n; ++i) {
            value[cityDegree[i].second] = n - i;
        }

        // Calculate total importance
        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += value[road[0]] + value[road[1]];
        }

        return totalImportance;
    }
};