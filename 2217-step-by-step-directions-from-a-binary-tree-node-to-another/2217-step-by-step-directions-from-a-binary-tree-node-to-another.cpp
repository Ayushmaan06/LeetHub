class Solution {
    bool getPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;

        path.push_back('L');
        if (getPath(root->left, value, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (getPath(root->right, value, path)) return true;
        path.pop_back();

        return false;
    }
    
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue) {
        if (!root || root->val == startValue || root->val == destValue) return root;
        TreeNode* left = findLCA(root->left, startValue, destValue);
        TreeNode* right = findLCA(root->right, startValue, destValue);
        if (left && right) return root;
        return left ? left : right;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        string pathToStart, pathToDest;
        getPath(lca, startValue, pathToStart);
        getPath(lca, destValue, pathToDest);
        
        // Convert pathToStart to 'U'
        string result(pathToStart.size(), 'U');
        result += pathToDest;
        return result;
    }
};
