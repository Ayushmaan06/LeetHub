class Solution {
public:
    vector<int> v;

    void ino(TreeNode* r){
        if(!r) return;
        ino(r->left);
        v.push_back(r->val);
        ino(r->right);
    }

    bool findTarget(TreeNode* root, int k) {
        ino(root);
        int i = 0, j = v.size() - 1;
        while (i < j) {
            int sum = v[i] + v[j];
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }
};
