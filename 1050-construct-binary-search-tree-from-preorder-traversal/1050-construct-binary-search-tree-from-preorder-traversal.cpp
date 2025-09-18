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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* r = new TreeNode(pre[0]);
        for(int i = 1 ; i< pre.size() ; i++){
            int x = pre[i];
            TreeNode* t = r;
            while(true){
                if(x>t->val){
                    if(t->right)t=t->right;
                    else {
                        TreeNode* d = new TreeNode(x);
                        t->right = d;
                        break;
                    }
                }
                else{
                    if(t->left)t=t->left;
                    else{
                        TreeNode* d = new TreeNode(x);
                        t->left = d;
                        break;
                    }
                }
            }
        }
        return r;
    }
};