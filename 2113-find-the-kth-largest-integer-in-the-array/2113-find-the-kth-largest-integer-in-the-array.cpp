

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // Sort the numbers based on their numerical values
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            if (a.size() == b.size()) return a < b; // If same length, compare lexicographically
            return a.size() < b.size(); // Otherwise, compare based on length
        });
        
        // The k-th largest number is at this index after sorting
        return nums[nums.size() - k];
    }
};