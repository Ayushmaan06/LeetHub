class Solution {
public:
    int candy(vector<int>& ratings) {
        int k = ratings.size();
        vector<int> v(k, 1);
        for (int i = 1; i < k; i++) {
            if (ratings[i] > ratings[i - 1]) {
                v[i] = v[i - 1] + 1;
            }
        }
        for (int i = k - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                v[i] = max(v[i], v[i + 1] + 1);
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};