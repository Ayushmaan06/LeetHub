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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* r = root;
        if(!root)return root =  new TreeNode(val);
        while(r){
            int x = r->val;
            if(x>val){
                if(!r->left){ r->left = new TreeNode(val); return root;}
                r=r->left;
            }
            else{
                if(!r->right){ r->right = new TreeNode(val); return root;}
                r=r->right;
            }
        }
        return root;
    }
};