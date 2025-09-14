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
    vector<int> v;
    void post(TreeNode* r){
        if(!r)return;
        post(r->left);
        post(r->right);
        v.push_back(r->val);
    }
    bool evaluateTree(TreeNode* r) {
        post(r);
        stack<int> st;
        for(int i : v){
            if(i==0 || i==1)st.push(i);
            else{
                int x=st.top();st.pop();int y = st.top(); st.pop();
                if(i==2)st.push(x|y);
                else st.push(x&y);
            }
        }
        return st.top();
    }
};