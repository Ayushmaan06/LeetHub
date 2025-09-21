class Solution {
public:
    vector<TreeNode*> nodes;
    
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        
        for (int i = 0; i + 1 < nodes.size(); i++) {
            if (nodes[i]->val > nodes[i+1]->val) {
                if (!first) first = nodes[i];
                second = nodes[i+1];
            }
        }
        
        swap(first->val, second->val);
    }
};
