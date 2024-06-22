class Solution {
public:
    vector<int> nextSmallerElementLeft(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    
    vector<int> nextSmallerElementRight(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = nextSmallerElementLeft(arr);
        vector<int> right = nextSmallerElementRight(arr);
        
        long long sum = 0;
        long long mod = 1e9 + 7;
        
        for (int i = 0; i < n; ++i) {
            int leftDist = (left[i] == -1 ? i + 1 : i - left[i]);
            int rightDist = (right[i] == n ? n - i : right[i] - i);
            
            sum = (sum + (long long)arr[i] * leftDist * rightDist) % mod;
        }
        
        return sum;
    }
};
