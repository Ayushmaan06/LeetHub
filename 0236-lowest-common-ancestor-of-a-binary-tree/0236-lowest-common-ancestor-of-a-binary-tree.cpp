/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void f(TreeNode* x, TreeNode* r , vector<TreeNode*>& t, vector<TreeNode*>& res){
        if (r == nullptr) return;
        if (r == x) {  
            t.push_back(r);
            res = t;
            return;
        }
        t.push_back(r);
        if (r->left) { f(x, r->left, t, res); t.pop_back(); }
        if (r->right) { f(x, r->right, t, res); t.pop_back(); }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a, b, tmp;
        f(p, root, tmp, a);
        tmp.clear();
        f(q, root, tmp, b);

        unordered_map<TreeNode*, int> mp;
        TreeNode* ans = nullptr;

        for (TreeNode* node : a) mp[node]++;
        for (TreeNode* node : b) {
            if (mp.find(node) != mp.end()) ans = node;
        }
        return ans;
    }
};
