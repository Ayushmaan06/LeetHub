class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n=arr.size();
        int l = 0, h = n - 1, m;
        while (l <= h) {
            m = (l + h) / 2;
            if (arr[m] == k) {
                return m;
            }

            if (arr[m] <= arr[h]) {
                if (arr[m] < k && k <= arr[h]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            } else {
                if (arr[l] <= k && k < arr[m]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
    
};