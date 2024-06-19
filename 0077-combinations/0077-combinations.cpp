class Solution {
public:
    void solve(vector<int> o, vector<int> i, int k, vector<vector<int>>& v, int start) {
        if (o.size() == k) {
            v.push_back(o); // Corrected to push back the vector 'o' instead of 'k'
            return;
        }
        for (int j = start; j < i.size(); j++) {
            o.push_back(i[j]); // Correctly add the element to 'o'
            solve(o, i, k, v, j + 1); // Pass 'j + 1' instead of 'start + 1' to ensure the next element is considered
            o.pop_back(); // Remove the last element to backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> j;
        vector<int> o;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            j.push_back(i + 1); // Correctly add elements to 'j'
        }
        solve(o, j, k, v, 0);
        return v;
    }
};