#define ll long long

class Solution {
public:
    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> arr(n, 0);
        unordered_map<int, ll> count, sum;
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            arr[i] += (ll)i * count[val] - sum[val];
            count[val]++;
            sum[val] += i;
        }
        count.clear();
        sum.clear();
        for (int i = n - 1; i >= 0; i--) {
            int val = nums[i];
            arr[i] += sum[val] - (ll)i * count[val];
            count[val]++;
            sum[val] += i;
        }

        return arr;
    }
};