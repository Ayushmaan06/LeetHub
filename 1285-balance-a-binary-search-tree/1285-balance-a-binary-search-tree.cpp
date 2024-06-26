class Solution {
public:
    // Function to perform in-order traversal and fill the values vector.
    void inorderTraversal(TreeNode* root, vector<int>& values) {
        if (!root) return;
        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }

    // Function to build a balanced BST from sorted values.
    TreeNode* buildBalancedBST(vector<int>& values, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(values[mid]);
        node->left = buildBalancedBST(values, start, mid - 1);
        node->right = buildBalancedBST(values, mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorderTraversal(root, values); // Step 1: In-order traversal to get sorted values
        return buildBalancedBST(values, 0, values.size() - 1); // Step 2: Build balanced BST
    }
};