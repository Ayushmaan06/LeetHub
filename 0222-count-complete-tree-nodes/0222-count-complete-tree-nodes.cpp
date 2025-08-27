class Solution {
public:
    int leafCount(TreeNode* root, int level, int h) {
        if (!root) return 0;
        if (level == h) return 1; 
        return leafCount(root->left, level+1, h) + leafCount(root->right, level+1, h);
    }

    int height(TreeNode* r) {
        if (!r) return 0;
        return 1 + height(r->left);
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = height(root);
        int res = 0;
        for (int i = 0; i < h-1; i++) {
            res += (1 << i);
        }
        res += leafCount(root, 1, h);
        return res;
    }
};
