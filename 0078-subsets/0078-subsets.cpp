class Solution {
public:
    void solve(vector<int>& in, vector<vector<int>>& ans, vector<int>& out,int n , int i){
        if(i==n){
            ans.push_back(out);
            return;
        }
        out.push_back(in[i]);
        solve(in, ans, out, n, i+1);
        out.pop_back();
        solve(in, ans, out, n, i+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& in) {
        vector<vector<int>> ans;
        vector<int> out;
        solve(in, ans, out, in.size(), 0);
        return ans;
    }
};