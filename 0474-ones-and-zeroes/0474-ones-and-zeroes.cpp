class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<pair<int, int>> count; 
    int l; 
    int dfs(int idx, int m_left, int n_left) {
        if (idx == l) return 0;
        if (dp[idx][m_left][n_left] != -1) return dp[idx][m_left][n_left];
        int res = dfs(idx + 1, m_left, n_left);
        int zeros = count[idx].first;
        int ones = count[idx].second;
        if (m_left >= zeros && n_left >= ones) {
            res = max(res, 1 + dfs(idx + 1, m_left - zeros, n_left - ones));
        }
        return dp[idx][m_left][n_left] = res;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        l = strs.size();
        count.resize(l);
        for (int i = 0; i < l; ++i) {
            int zeros = count_if(strs[i].begin(), strs[i].end(), [](char c){ return c == '0'; });
            int ones = strs[i].size() - zeros;
            count[i] = {zeros, ones};
        }
        dp.assign(l, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(0, m, n);
    }
};
