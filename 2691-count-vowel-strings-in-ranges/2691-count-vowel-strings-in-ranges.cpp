class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c); // Convert character to lowercase
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> v(n + 1, 0);
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                v[i + 1] = 1; 
            }
        }

        for (int i = 1; i <= n; ++i) {
            v[i] += v[i - 1]; // Cumulative sum
        }

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(v[r + 1] - v[l]); 
        }

        return ans;
    }
};
