class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size(); // Length of the string
        string t = s; // Initialize the resulting string with the original string

        // Iterate over each character in the string
        for (int i = 0; i < n; ++i) {
            // Iterate over each lowercase English letter ('a' to 'z')
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                // Calculate the minimum distance to change s[i] to ch
                int dist = min(abs(s[i] - ch), min(s[i] + 26 - ch, ch + 26 - s[i]));
                // If the distance is within the allowed value k, update the character in the resulting string
                if (dist <= k) {
                    t[i] = ch;
                    // Reduce k by the distance changed
                    k -= dist;
                    // Move to the next character in the original string
                    break; 
                }
            }
        }
        return t; 
    }
};