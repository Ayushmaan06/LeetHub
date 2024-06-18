class Solution {
public:
    void solve(vector<int>& i, vector<int> o, int k, int s,int si , int l, vector<vector<int>>& r, int start) {
        if (s > k || si>l) {
            return;
        }
        if (s == k && si==l) {
            sort(o.begin(), o.end());
            r.push_back(o);
            return;
        }
        for (int j = start; j < i.size(); ++j) {
            // Skip duplicates
            if (j > start && i[j] == i[j - 1]) continue;
            o.push_back(i[j]);
            solve(i, o, k, s + i[j],si+1, l, r, j + 1);
            o.pop_back();  // backtrack
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> in;
        for(int i = 1 ; i <10 ; i++){
            in.push_back(i);
        }
        vector<vector<int>> result;
        vector<int> current;

        solve(in, current, n, 0,0,k, result, 0);
        return result;
    }
};