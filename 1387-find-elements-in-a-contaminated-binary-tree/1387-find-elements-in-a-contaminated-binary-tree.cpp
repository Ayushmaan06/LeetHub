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
class FindElements {
public:
    unordered_set<int> v;
    void fix(TreeNode* r){
        if(!r)return;
        if(r->left)r->left->val=2*r->val+1,v.insert(r->left->val);
        if(r->right)r->right->val=2*r->val+2,v.insert(r->right->val);
        fix(r->left);
        fix(r->right);
    }
    FindElements(TreeNode* root) {
        if(root)root->val=0,v.insert(0);
        fix(root);
    }
    
    bool find(int target) {
        return (v.find(target)!=v.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */