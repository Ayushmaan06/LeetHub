class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        if (v[n-1] != 9) {
            v[n-1]++;
            return v;
        }
        int j = n - 1;
        while (j >= 0 && v[j] == 9) {
            v[j] = 0;
            j--;
        }
        if (j < 0) v.insert(v.begin(), 1);
        else v[j]++;
        return v;
    }
};
