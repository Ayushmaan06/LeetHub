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
    bool ans=true;
    int x(TreeNode* r){
        if(!r)return 0;
        int ld = 1 + x(r->left);
        int rd = 1 + x(r->right);
        if(abs(ld-rd)>1)ans=false;
        return max(ld,rd);
    }
    bool isBalanced(TreeNode* root) {
        
        x(root);
        return ans;
    }
};
