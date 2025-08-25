/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long
class Solution {
public:
    ll widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0}); // start index = 0
        ll ans = 0;

        while (!q.empty()) {
            ll n = q.size();
            ll first = q.front().second;
            ll last = q.back().second;

            ans = max(ans, last - first + 1);

            for (ll i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();
                // Normalize index by subtracting `first` so numbers stay small
                idx -= first; 
                if (node->left)  q.push({node->left, 2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }
        }
        return ans;
    }
};
