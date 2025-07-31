class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& col, int k) {
        int n = col.size();
        int ans = 0, alt = 0;
        int prev = col[0];

        for(int i = 1; i < n + k; ++i){
            int curr = col[i % n];
            if(curr != prev) alt++;
            else alt = 1;
            prev = curr;

            if(alt >= k) ans++;
        }

        return ans;
    }
};
