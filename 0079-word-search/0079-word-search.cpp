class Solution {
public:
    bool flag=false;
    void solve(vector<vector<char>>& b, string word,int i , int r, int c){
        if(flag)return;
        if(r<0 || r >= b.size() || c<0 || c>= b[0].size()) return ;
        if(i==word.length()-1 && word[i] == b[r][c]){flag=true;return;}
        if(word[i] == b[r][c]){
            char temp = b[r][c];
            b[r][c]='.';
            solve(b,word,i+1,r,c+1);
            solve(b,word,i+1,r,c-1);
            solve(b,word,i+1,r+1,c);
            solve(b,word,i+1,r-1,c);
            b[r][c]=temp;
        }
        return;
    }
    bool exist(vector<vector<char>>& b, string word) {
        int n = b.size(),m=b[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(b[i][j] == word[0]){
                    solve(b,word,0,i,j);
                    if(flag)return flag;
                }
            }
        }
        return flag;
    }
};
