class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head, *curr = head->next;
        int pos = 1, firstCriticalPos = -1, lastCriticalPos = -1, minDistance = INT_MAX;
        
        while (curr->next != nullptr) {
            // Check if current node is a critical point
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (firstCriticalPos != -1) {
                    // Update minDistance
                    minDistance = min(minDistance, pos - lastCriticalPos);
                } else {
                    firstCriticalPos = pos; // First critical point found
                }
                lastCriticalPos = pos; // Update last critical point position
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        if (firstCriticalPos == -1 || firstCriticalPos == lastCriticalPos) {
            return {-1, -1}; // Fewer than two critical points
        }
        
        // Calculate maxDistance
        int maxDistance = lastCriticalPos - firstCriticalPos;
        return {minDistance, maxDistance};
    }
};