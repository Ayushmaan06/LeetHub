class Solution {
public:
    unordered_map<TreeNode*, long long> mp;
    
    long long sum(TreeNode* h){
        if (!h) return 0;
        long long lsum = sum(h->left);
        long long rsum = sum(h->right);
        return mp[h] = lsum + rsum + h->val;
    }

    int maxProduct(TreeNode* root) {
        long long a = sum(root);
        queue<TreeNode*> q;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
        
        long long ans = 0;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            
            ans = max(ans, mp[t] * (a - mp[t]));
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        
        return ans % 1000000007;
    }
};