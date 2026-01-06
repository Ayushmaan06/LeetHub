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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ms=INT_MIN,cs=0,j=1,ans;
        while(!q.empty()){
            int n = q.size();cs=0;
            for(int i = 0 ; i < n ; i++){
                TreeNode* t = q.front();q.pop();
                cs+=t->val;
                if(t->right)q.push(t->right);
                if(t->left)q.push(t->left);
            }
            if(cs>ms){ms=cs;ans=j;}j++;
        }
        return ans;
    }
};