class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root, int path = 0) {
        if (!root) return 0;
        path ^= (1 << root->val);
        if (!root->left && !root->right) return (path & (path - 1)) == 0 ? 1 : 0;
        return pseudoPalindromicPaths(root->left, path) +
               pseudoPalindromicPaths(root->right, path);
    }
};
