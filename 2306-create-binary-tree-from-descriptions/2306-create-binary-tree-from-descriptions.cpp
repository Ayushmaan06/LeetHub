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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> nodeMap; // Maps value to TreeNode
    unordered_set<int> children; // Keeps track of all nodes that are children

    for (const auto& desc : descriptions) {
        int parentVal = desc[0], childVal = desc[1];
        bool isLeft = desc[2];

        // Ensure both parent and child nodes exist
        if (nodeMap.find(parentVal) == nodeMap.end()) {
            nodeMap[parentVal] = new TreeNode(parentVal);
        }
        if (nodeMap.find(childVal) == nodeMap.end()) {
            nodeMap[childVal] = new TreeNode(childVal);
        }

        // Link parent and child
        if (isLeft) {
            nodeMap[parentVal]->left = nodeMap[childVal];
        } else {
            nodeMap[parentVal]->right = nodeMap[childVal];
        }

        // Mark child
        children.insert(childVal);
    }

    // Find root (a node that is not a child)
    TreeNode* root = nullptr;
    for (const auto& desc : descriptions) {
        if (children.find(desc[0]) == children.end()) {
            root = nodeMap[desc[0]];
            break;
        }
    }

    return root;
}
};