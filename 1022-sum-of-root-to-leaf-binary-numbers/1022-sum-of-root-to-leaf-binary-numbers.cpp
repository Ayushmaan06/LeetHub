class Solution {
public:
    vector<string> v;
    void x(TreeNode* r, string s){
        if(!r) return; 
        s += to_string(r->val);
        if(!r->left && !r->right) {
            v.push_back(s);
            return;
        }
        
        x(r->left, s);
        x(r->right, s);
    }

    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0; 
        string s = "";
        x(root, s);
        int ans = 0;
        for(string r : v){
            ans += stoi(r, nullptr, 2);
        }
        return ans;
    }
};