class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        root = deleteNodes(root, toDeleteSet, forest);
        if (root) forest.push_back(root); // If root is not deleted, add it to the forest
        return forest;
    }

private:
    TreeNode* deleteNodes(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        node->left = deleteNodes(node->left, toDeleteSet, forest); // Process left child
        node->right = deleteNodes(node->right, toDeleteSet, forest); // Process right child
        if (toDeleteSet.count(node->val)) { // If current node needs to be deleted
            if (node->left) forest.push_back(node->left); // Add non-null children to forest
            if (node->right) forest.push_back(node->right);
            delete node; // Free the memory of the current node
            return nullptr; // Return nullptr to parent, indicating removal
        }
        return node; // Return the current node if it's not deleted
    }
};