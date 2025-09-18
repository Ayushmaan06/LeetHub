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
    TreeNode* build(vector<int>& nums, int st, int en) {
        if (st > en) return nullptr;
        int mi = max_element(nums.begin() + st, nums.begin() + en + 1) - nums.begin();
        TreeNode* root = new TreeNode(nums[mi]);
        root->left = build(nums, st, mi - 1);
        root->right = build(nums, mi + 1, en);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};
