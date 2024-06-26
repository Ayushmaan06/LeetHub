class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited(numCourses, false), recStack(numCourses, false);

        // Building the graph
        for (const auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        // Check for cycles in the graph
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (isCyclic(i, graph, visited, recStack)) return false;
            }
        }
        return true;
    }

private:
    bool isCyclic(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbour : graph[node]) {
            if (!visited[neighbour]) {
                if (isCyclic(neighbour, graph, visited, recStack)) return true;
            } else if (recStack[neighbour]) {
                return true; // Found a cycle
            }
        }

        recStack[node] = false; // Remove the node from recursion stack before returning
        return false;
    }
};