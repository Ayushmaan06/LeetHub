class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return vector<int>(distance + 1, 0);
        if (!node->left && !node->right) {
            vector<int> leafDist(distance + 1, 0);
            leafDist[1] = 1; // Leaf node at distance 1 from itself
            return leafDist;
        }

        vector<int> leftDist = dfs(node->left, distance, count);
        vector<int> rightDist = dfs(node->right, distance, count);

        // Count good leaf node pairs
        for (int i = 1; i <= distance; ++i) {
            for (int j = 1; j <= distance - i; ++j) {
                count += leftDist[i] * rightDist[j];
            }
        }

        // Combine distances for the current node
        vector<int> currDist(distance + 1, 0);
        for (int i = 2; i <= distance; ++i) {
            currDist[i] = leftDist[i - 1] + rightDist[i - 1];
        }

        return currDist;
    }
};