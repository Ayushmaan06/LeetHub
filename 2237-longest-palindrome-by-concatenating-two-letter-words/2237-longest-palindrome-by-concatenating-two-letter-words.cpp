class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (const string& w : words) {
            mp[w]++;
        }

        int ans = 0;
        bool hasOddPalindrome = false;

        for (auto& [word, count] : mp) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word == rev) {
                ans += (count / 2) * 4;
                if (count % 2 == 1) {
                    hasOddPalindrome = true;
                }
            } else if (word < rev && mp.count(rev)) {
                int pairs = min(count, mp[rev]);
                ans += pairs * 4;
            }
        }

        if (hasOddPalindrome) ans += 2; 
        return ans;
    }
};
