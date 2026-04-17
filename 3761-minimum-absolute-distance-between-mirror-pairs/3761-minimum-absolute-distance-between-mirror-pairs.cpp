class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int minDist = INT_MAX;
        
        // Map from reversed number to the most recent index where it appeared as reverse(nums[i])
        // Actually we need: for each index i, we add reverse(nums[i]) -> i
        // Then for j, we check if nums[j] is in the map
        
        unordered_map<int, int> revToIndex; // reverse(nums[i]) -> index i
        
        for (int j = 0; j < n; j++) {
            // Check if there's i < j where reverse(nums[i]) == nums[j]
            if (revToIndex.count(nums[j])) {
                int i = revToIndex[nums[j]];
                minDist = min(minDist, j - i); // j > i, so abs(j-i) = j-i
            }
            
            // Add current number's reverse for future pairs
            int rev = reverseNum(nums[j]);
            // Only keep the most recent index to minimize distance
            // Actually, we should keep the largest index (most recent) to minimize j-i for future j
            revToIndex[rev] = j;
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
    
private:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};
