class Solution {
public:
    bool differByOneChange(const string& str1, const string& str2) {
        // Since both strings have the same length, we only need to check one length
        int differences = 0;
        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] != str2[i]) {
                ++differences;
                if (differences > 1) {
                    return false; // More than one difference found
                }
            }
        }
        return differences == 1; // True if exactly one difference, false otherwise
    }

    int ladderLength(string bw, string ew, vector<string>& wl) {
        queue<string> q;
        q.push(bw);
        int c = 1; // Start with 1 to count the initial word
        vector<bool> v(wl.size(), false);
        
        while (!q.empty()) {
            int size = q.size(); // Number of elements at the current level
            for (int k = 0; k < size; ++k) {
                string current = q.front();
                q.pop();

                for (int i = 0; i < wl.size(); ++i) {
                    if (!v[i] && differByOneChange(current, wl[i])) {
                        if (wl[i] == ew) {
                            return c + 1; // Return the level count when the end word is found
                        }
                        q.push(wl[i]);
                        v[i] = true;
                    }
                }
            }
            ++c; // Increment level count after finishing the current level
        }
        
        return 0; // Return 0 if no valid transformation sequence is found
    }
};
