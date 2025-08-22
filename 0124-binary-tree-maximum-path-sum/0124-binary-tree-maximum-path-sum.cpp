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
    int ans=INT_MIN;
    int x(TreeNode* r){
        if(!r)return 0;
        int lv = max(0,x(r->left)), rv =max(0,x(r->right));
        ans=max(ans,(r->val+lv+rv));
        return r->val + max(lv,rv);
    }
public:
    int maxPathSum(TreeNode* root) {
        x(root);
        return ans;
    }
};