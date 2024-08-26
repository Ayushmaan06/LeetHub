class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};

        vector<int> result;
        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            result.insert(result.begin(), node->val);

            for (Node* child : node->children) {
                stk.push(child);
            }
        }

        return result;
    }
};