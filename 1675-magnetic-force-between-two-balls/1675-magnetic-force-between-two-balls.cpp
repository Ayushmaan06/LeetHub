
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position.back() - position.front();
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(position, m, mid)) {
                result = mid; // If it's possible to place all balls, update the result
                low = mid + 1; // Try a larger distance
            } else {
                high = mid - 1; // Try a smaller distance
            }
        }
        
        return result;
    }
    
    bool canPlaceBalls(const vector<int>& position, int m, int distance) {
        int count = 1; // Place the first ball
        int lastPosition = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPosition >= distance) {
                lastPosition = position[i];
                count++;
                if (count == m) return true; // Successfully placed all balls
            }
        }
        return false; // Couldn't place all balls
    }
};