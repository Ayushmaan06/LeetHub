class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(),m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int a1=0,a2=0;
        for(char c : s1)a1+=(int)(c);
        for(char c : s2)a2+=(int)(c);
        for(int i = 0 ; i < m ; i++){
            dp[n][i]=a2;
            a2=a2-(int)(s2[i]);
        }
        for(int i = 0 ; i < n ; i++){
            dp[i][m]=a1;
            a1=a1-(int)(s1[i]);
        }
        dp[n][m]=0;
        for(int i =n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                int c1 = (int)(s1[i]);
                int c2 = (int)(s2[j]);
                if(s1[i] == s2[j])dp[i][j]=dp[i+1][j+1];
                else dp[i][j]=min(dp[i+1][j]+c1 , dp[i][j+1]+c2);
            }
        }
        return dp[0][0];
    }
};