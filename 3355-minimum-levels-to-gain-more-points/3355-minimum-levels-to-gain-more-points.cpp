class Solution {
public:
    int minimumLevels(vector<int>& pos) {
        int sc = 0;
        for (int p : pos) {
            if (p) sc++;
            else sc--;
        }
        int t = sc;
        sc = 0; 
        int ans = 0;
        int n = pos.size();

        for (int p : pos) {
            if (p) sc++;
            else sc--;

            ans++;

            if (sc > t - sc && ans < n) { 
                return ans; 
            }
        }
        return -1;
    }
};
