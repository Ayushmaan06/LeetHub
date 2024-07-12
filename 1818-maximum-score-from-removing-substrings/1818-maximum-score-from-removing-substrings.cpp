class Solution {
public:
    int maximumGain(string str, int x, int y) {
        int cx = 0, cy = 0;
        string stack1, stack2;
        
        // Prioritize the higher score pair
        if (x > y) {
            // Remove "ab" first
            for (char c : str) {
                if (!stack1.empty() && stack1.back() == 'a' && c == 'b') {
                    stack1.pop_back();
                    cx++;
                } else {
                    stack1.push_back(c);
                }
            }
            // Remove "ba" from the remaining string
            for (char c : stack1) {
                if (!stack2.empty() && stack2.back() == 'b' && c == 'a') {
                    stack2.pop_back();
                    cy++;
                } else {
                    stack2.push_back(c);
                }
            }
        } else {
            // Remove "ba" first
            for (char c : str) {
                if (!stack1.empty() && stack1.back() == 'b' && c == 'a') {
                    stack1.pop_back();
                    cy++;
                } else {
                    stack1.push_back(c);
                }
            }
            // Remove "ab" from the remaining string
            for (char c : stack1) {
                if (!stack2.empty() && stack2.back() == 'a' && c == 'b') {
                    stack2.pop_back();
                    cx++;
                } else {
                    stack2.push_back(c);
                }
            }
        }
        
        return cx * x + cy * y;
    }
};
