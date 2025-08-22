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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int f = 1;
        vector<vector<int>> res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> t;
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                TreeNode* r = q.front();
                q.pop();
                t.push_back(r->val);
                if(r->left)q.push(r->left);
                if(r->right)q.push(r->right);
            }
            if(!f)reverse(t.begin(),t.end());
            res.push_back(t);
            f=f^1;
        }
        return res;
    }
};