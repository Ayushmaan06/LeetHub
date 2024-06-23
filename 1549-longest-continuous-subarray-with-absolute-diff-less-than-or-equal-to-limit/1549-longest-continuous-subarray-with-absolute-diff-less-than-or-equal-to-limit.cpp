#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        multiset<int> windowElements;
        int left = 0, maxLength = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Add the current element to the multiset (window)
            windowElements.insert(nums[right]);
            
            // Check if the current window satisfies the condition
            while (*windowElements.rbegin() - *windowElements.begin() > k) {
                // If not, remove the leftmost element and move the left pointer
                windowElements.erase(windowElements.find(nums[left]));
                left++;
            }
            
            // Update the maximum length of the subarray
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};