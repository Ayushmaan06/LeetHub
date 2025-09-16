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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool e = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            for(int i = 0 ; i < n ; i++){
                TreeNode* r = q.front(); q.pop();
                t.push_back(r->val);
                if(r->left)q.push(r->left);
                if(r->right)q.push(r->right);
            }
            if(e){
                for(int i : t)if(i%2==0)return false;
                for(int i = 1 ; i < n ; i++)if(t[i-1]>=t[i]) return false;
            }
            else{
                for(int i : t)if(i%2)return false;
                for(int i = 1 ; i < n ; i++)if(t[i-1]<=t[i]) return false;
            }
            e=!e;
        }
        return true;
    }
};