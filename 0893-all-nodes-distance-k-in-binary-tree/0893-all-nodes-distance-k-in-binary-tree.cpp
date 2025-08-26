class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj) {
        if (!root) return;
        if (root->left) {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            buildGraph(root->left, adj);
        }
        if (root->right) {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            buildGraph(root->right, adj);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        buildGraph(root, adj);

        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis.insert(target);

        int dist = 0;
        while (!q.empty()) {
            int n = q.size();
            if (dist == k) {
                vector<int> res;
                while (!q.empty()) {
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }
            for (int i = 0; i < n; i++) {
                TreeNode* u = q.front(); q.pop();
                for (TreeNode* v : adj[u]) {
                    if (!vis.count(v)) {
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
            dist++;
        }
        return {};
    }
};
