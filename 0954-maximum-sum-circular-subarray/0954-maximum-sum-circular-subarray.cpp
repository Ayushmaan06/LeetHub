class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN, currentMax = 0;
        int minSum = INT_MAX, currentMin = 0;
        
        for (int num : nums) {
            // Calculate total sum of the array
            totalSum += num;
            
            // Kadane's algorithm to find the maximum subarray sum
            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);
            
            // Kadane's algorithm to find the minimum subarray sum
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
        }
        
        // Handle the case where all numbers are negative
        if (maxSum < 0) {
            return maxSum;
        }
        
        // The result is the maximum of the non-circular and circular subarray sums
        return max(maxSum, totalSum - minSum);
    }
};
