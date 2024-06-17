
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> s1Map, s2Map;
        // Initialize frequency maps for s1 and the first window in s2
        for (int i = 0; i < s1.length(); ++i) {
            s1Map[s1[i]]++;
            s2Map[s2[i]]++;
        }

        int count = 0;
        // Compare maps and count matches
        for (int i = 0; i < 26; i++) {
            if (s1Map['a' + i] == s2Map['a' + i])
                count++;
        }

        for (int i = 0; i < s2.length() - s1.length(); ++i) {
            if (count == 26) return true; // All characters match

            // Update the window
            char r = s2[i + s1.length()], l = s2[i];
            if (s1Map[r] == s2Map[r]) count--;
            s2Map[r]++;
            if (s1Map[r] == s2Map[r]) count++;

            if (s1Map[l] == s2Map[l]) count--;
            s2Map[l]--;
            if (s1Map[l] == s2Map[l]) count++;
        }

        return count == 26; // Check the last window
    }
};