class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            diff[start] += direction == 1 ? 1 : -1;
            diff[end + 1] += direction == 1 ? -1 : 1;
        }

        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; ++i) {
            int shift = (diff[i] % 26 + 26) % 26; // Ensure positive shift within [0, 25]
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};