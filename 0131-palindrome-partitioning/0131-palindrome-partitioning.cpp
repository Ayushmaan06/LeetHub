class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, vector<vector<string>>& ans,int n, int i,vector<string>& ds) {
        if(i==n)ans.push_back(ds);
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                ds.push_back(s.substr(i,j-i+1));
                solve(s,ans,n,j+1,ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        solve(s,ans,s.length(),0,ds);
        return ans;
    }
};