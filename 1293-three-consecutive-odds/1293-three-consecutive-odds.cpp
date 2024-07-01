class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
    // Initialize count of consecutive odd numbers
    int count = 0;

    // Iterate through the array
    for (int num : arr) {
        // If the number is odd, increment the count
        if (num % 2 != 0) {
            count++;
            // If we have found three consecutive odd numbers, return true
            if (count == 3) return true;
        } else {
            // Reset count if the current number is not odd
            count = 0;
        }
    }

    // Return false if no three consecutive odd numbers were found
    return false;
}
};