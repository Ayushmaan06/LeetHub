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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *r = root, *p = nullptr;
        while (r) {
            if (r->val == key) break;
            p = r;
            if (key < r->val) r = r->left;
            else r = r->right;
        }
        if (!r) return root; 
        TreeNode* rl = r->left;
        TreeNode* rr = r->right;
        if (!p) {
            if (!rl) return rr;
            TreeNode* temp = rl;
            while (temp->right) temp = temp->right;
            temp->right = rr;
            return rl;
        }
        bool isLeftChild = (p->left == r);

        if (rl) {
            if (isLeftChild) p->left = rl; else p->right = rl;
            TreeNode* temp = rl;
            while (temp->right) temp = temp->right;
            temp->right = rr;
        } else {
            if (isLeftChild) p->left = rr; else p->right = rr;
        }

        return root;
    }
};