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
    void in(TreeNode* r, vector<int>& res){
        if(!r)return;
        in(r->left,res);res.push_back(r->val);in(r->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        in(root,res);
        return res;
    }
};