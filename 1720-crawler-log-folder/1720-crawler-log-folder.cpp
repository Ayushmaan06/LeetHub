class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0; // Counter for the depth
        for (const string& log : logs) {
            if (log == "../") {
                if (depth > 0) depth--; // Move up to the parent folder, if not already in the main folder
            } else if (log != "./") {
                depth++; // Move down to a child folder
            }
            // If log == "./", do nothing
        }
        return depth; // The depth is the minimum number of operations needed to return to the main folder
    }
};