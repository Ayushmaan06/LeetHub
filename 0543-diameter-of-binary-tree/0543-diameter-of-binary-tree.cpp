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
    int ans=-1;
    int x(TreeNode* r){
        if(!r)return 0;
        int lh = x(r->left),rh=x(r->right); 
        ans=max(ans,(lh+rh));
        return 1 + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        x(root);
        return ans;
    }
};