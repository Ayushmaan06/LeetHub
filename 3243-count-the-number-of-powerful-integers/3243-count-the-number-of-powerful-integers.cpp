class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countChakraShinobi(finish, limit, s) - countChakraShinobi(start - 1, limit, s);
    }

private:
    long long countChakraShinobi(long long val, int limit, const string& clanSymbol) {
        string chakraFlow = to_string(val);  
        int prefixLength = chakraFlow.length() - clanSymbol.length();  

        if (prefixLength < 0) return 0; 
        vector<vector<long long>> dp(prefixLength + 1, vector<long long>(2, 0));

        dp[prefixLength][0] = 1;  // Free path
        dp[prefixLength][1] = chakraFlow.substr(prefixLength) >= clanSymbol ? 1 : 0;

        for (int i = prefixLength - 1; i >= 0; --i) {
            int currentChakra = chakraFlow[i] - '0';

            dp[i][0] = (limit + 1) * dp[i + 1][0];

            if (currentChakra <= limit) {
                dp[i][1] = (long long) currentChakra * dp[i + 1][0] + dp[i + 1][1];
            } else {
                dp[i][1] = (long long)(limit + 1) * dp[i + 1][0];
            }
        }

        return dp[0][1];  
    }
};