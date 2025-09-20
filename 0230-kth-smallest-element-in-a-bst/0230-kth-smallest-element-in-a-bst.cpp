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
    vector<int> v;
    void ino(TreeNode* r){
        if(!r)return;
        ino(r->left);
        v.push_back(r->val);
        ino(r->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        ino(root);
        return v[k-1];
    }
};