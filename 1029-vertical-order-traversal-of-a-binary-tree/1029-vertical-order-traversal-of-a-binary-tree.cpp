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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while (!q.empty()){
            auto [node, col, row] = q.front();
            q.pop();
            mp[col].push_back({row, node->val});
            
            if (node->left)
                q.push({node->left, col - 1, row + 1});
            if (node->right)
                q.push({node->right, col + 1, row + 1});
        }
        vector<vector<int>> res;
        for (auto &p : mp){
            auto &vec = p.second;
            sort(vec.begin(), vec.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
                return (a.first == b.first) ? a.second < b.second : a.first < b.first;
            });
            vector<int> colVals;
            for (auto &pr : vec)
                colVals.push_back(pr.second);
            res.push_back(colVals);
        }
        return res;
    }
};