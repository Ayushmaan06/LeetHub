class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i++){
            unordered_set<char> r,c;
            int rr=0,cc=0;
            for(int j =0 ; j < 9 ; j++){
                if(board[i][j]!='.')r.insert(board[i][j]),rr++;
                if(board[j][i]!='.')c.insert(board[j][i]),cc++;
            }
            if(rr!=r.size() || cc!=c.size())return false;
        }
        for(int i =0 ; i<9 ; i+=3){
            for(int j = 0 ; j < 9 ; j+=3){
                unordered_set<char> s;int c=0;
                for(int k = i ; k < i+3 ; k++){
                    for(int l = j ; l<j+3 ; l++){
                         if(board[k][l]!='.')s.insert(board[k][l]),c++;
                    }
                }
                if(c!=s.size())return false;
            }
        }
        return true;
    }
};