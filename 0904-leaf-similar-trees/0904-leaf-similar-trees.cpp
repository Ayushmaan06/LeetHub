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
    void pre(TreeNode* r, vector<int>& v){
        if(!r)return;
        if(!r->left && !r->right)v.push_back(r->val);
        pre(r->left,v);
        pre(r->right,v);
    }
    bool leafSimilar(TreeNode* r1, TreeNode* r2) {
        vector<int> v1,v2;
        pre(r1,v1);pre(r2,v2);
        if(v1.size() != v2.size()) return false;
        for(int i = 0 ; i < v1.size() ; i++){
            if(v1[i]!=v2[i])return false;
        }
        return true;
    }
};