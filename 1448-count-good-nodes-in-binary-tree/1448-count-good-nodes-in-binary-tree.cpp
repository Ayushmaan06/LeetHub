class Solution {
public:
    int dfs(TreeNode* root, int currentMax) {
        if (!root) return 0;
        int good = 0;
        if (root->val >= currentMax) {
            good = 1;
            currentMax = root->val;
        }
        return good +
               dfs(root->left, currentMax) +
               dfs(root->right, currentMax);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
