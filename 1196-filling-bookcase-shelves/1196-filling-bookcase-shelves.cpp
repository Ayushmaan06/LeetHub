class Solution {
private:
    int helper(vector<vector<int>> &books, int idx, int remainingShelfWidth, int height, int shelfWidth, vector<vector<int>> &dp){
        if(idx >= books.size()) return height;
        if(dp[idx][remainingShelfWidth] != -1) return dp[idx][remainingShelfWidth];

        int currBookWidth  = books[idx][0];
        int currBookHeight = books[idx][1]; 
        int opt1 = height + helper(books, idx + 1, shelfWidth - currBookWidth, currBookHeight, shelfWidth, dp);
        int opt2 = INT_MAX;
        if(remainingShelfWidth >= currBookWidth){
            opt2 = helper(books, idx + 1, remainingShelfWidth - currBookWidth, max(height, currBookHeight), shelfWidth, dp);
        }
        return dp[idx][remainingShelfWidth] = min(opt1, opt2);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int sz = books.size();
        vector<vector<int>> dp(sz, vector<int>(shelfWidth + 1, -1));
        return helper(books, 0, shelfWidth, 0, shelfWidth, dp);
    }
};