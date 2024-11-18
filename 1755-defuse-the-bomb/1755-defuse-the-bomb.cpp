class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        bool flag = true;

        if (k == 0) {
            return ans; // All elements are replaced by 0 if k == 0
        }

        if (k < 0) {
            k *= -1;
            reverse(code.begin(), code.end());
            flag = false;
        }

        // Extend the circular array
        for (int i = 0; i < n; i++) {
            code.push_back(code[i]);
        }

        // Use the sliding window sum logic
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                ans[i] += code[i + j];
            }
        }

        if (!flag) {
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};
