
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Frequency map
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Sort based on the frequency and then by value decreasingly
        sort(nums.begin(), nums.end(), [&freq](int a, int b) {
            return freq[a] == freq[b] ? a > b : freq[a] < freq[b];
        });

        return nums;
    }
};