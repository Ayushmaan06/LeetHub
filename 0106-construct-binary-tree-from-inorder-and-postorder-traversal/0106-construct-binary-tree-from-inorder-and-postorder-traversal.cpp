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
    int i;
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& postorder, int st, int en) {
        if (st > en) return NULL;

        int val = postorder[i--];
        TreeNode* node = new TreeNode(val);
        int mid = mp[val];

        // Right subtree first (since postorder is being read in reverse)
        node->right = solve(postorder, mid + 1, en);
        node->left = solve(postorder, st, mid - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        i = postorder.size() - 1;

        for (int j = 0; j < inorder.size(); j++) {
            mp[inorder[j]] = j;
        }

        return solve(postorder, 0, inorder.size() - 1);
    }
};
