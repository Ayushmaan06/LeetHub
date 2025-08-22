/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int x(TreeNode* r){
        if(!r)return 0;
        return 1+max(x(r->left),x(r->right));
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return 1 + max(x(root->left),x(root->right));
    }
};