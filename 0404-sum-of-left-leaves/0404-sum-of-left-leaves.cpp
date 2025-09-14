class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        
        while (!q.empty()) {
            TreeNode* r = q.front();
            q.pop();
            
            // Check for left leaf
            if (r->left) {
                if (!r->left->left && !r->left->right) {
                    ans += r->left->val;
                } else {
                    q.push(r->left);
                }
            }
            
            if (r->right) {
                q.push(r->right);
            }
        }
        return ans;
    }
};
