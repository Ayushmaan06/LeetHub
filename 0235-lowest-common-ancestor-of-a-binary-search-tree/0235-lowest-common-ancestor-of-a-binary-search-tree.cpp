class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* l = p, *h = q, *r = root;
        if (p->val > q->val) h = p, l = q;
        while (r) {
            int x = r->val, a = l->val, b = h->val;
            if (x > b) r = r->left;
            else if (x < a) r = r->right;
            else return r;   
        }
        return NULL;
    }
};
