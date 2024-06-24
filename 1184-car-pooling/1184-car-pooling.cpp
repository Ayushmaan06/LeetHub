class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timestamp(1001, 0); // Use 1001 to cover up to 1000 as end location
        
        // Accumulate passenger changes at each start and end point
        for (const auto& trip : trips) {
            timestamp[trip[1]] += trip[0]; // Add passengers at start location
            timestamp[trip[2]] -= trip[0]; // Remove passengers at end location
        }
        
        int currentPassengers = 0;
        // Check if capacity is exceeded at any point
        for (int i = 0; i < 1001; ++i) {
            currentPassengers += timestamp[i];
            if (currentPassengers > capacity) {
                return false; // Capacity exceeded
            }
        }
        
        return true; // All trips are possible within capacity
    }
};