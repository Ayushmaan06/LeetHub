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
    int i=0;
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& v, int st, int en){
        if(st>en)return NULL;
        int d=v[i++];
        TreeNode* r = new TreeNode(d);
        int mid = mp[d];
        r->left=solve(v,st,mid-1);
        r->right=solve(v,mid+1,en);
        return r;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,0,inorder.size()-1);
    }
};