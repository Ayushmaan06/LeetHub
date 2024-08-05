class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
        
        // Count occurrences of each string
        for (const string& str : arr) {
            countMap[str]++;
        }
        
        // Find the kth distinct string
        int distinctCount = 0;
        for (const string& str : arr) {
            if (countMap[str] == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return str;
                }
            }
        }
        
        return "";
    }
};