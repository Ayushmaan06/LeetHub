class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBSTHelper(TreeNode* node, long long min, long long max) {
        if (!node) return true;  
        if (node->val <= min || node->val >= max) return false;
        return isValidBSTHelper(node->left, min, node->val) && isValidBSTHelper(node->right, node->val, max);
    }
};
