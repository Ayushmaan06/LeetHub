class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(vector<char> v : b){
            unordered_set<int> s;
            for(char c : v){
                if(isdigit(c)){
                    if(s.count(c-'0'))return false;
                    s.insert(c-'0');
                }
            }
        }
        for(int i = 0 ; i < 9 ; i++){
            unordered_set<int> s;
            for(int j = 0 ; j < 9 ; j++){
                char c = b[j][i];
                if(isdigit(c)){
                    if(s.count(c-'0'))return false;
                    s.insert(c-'0');
                }
            }
        }
        for(int i = 0 ; i < 9 ; i+=3){
            for(int j = 0 ; j < 9 ; j+=3){
                unordered_set<int> s;
                for(int x = i ; x < i+3 ; x++){
                    for(int y = j ; y < j+3 ; y++){
                        char c = b[x][y];
                        if(isdigit(c)){
                            if(s.count(c-'0'))return false;
                            s.insert(c-'0');
                        }
                    }
                }
            }
        }
        return true;
    }
};
