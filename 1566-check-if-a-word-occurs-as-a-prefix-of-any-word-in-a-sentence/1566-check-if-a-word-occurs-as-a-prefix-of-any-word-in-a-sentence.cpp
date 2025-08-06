class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string temp = "";
        int index = 1;
        for(int i = 0; i<sentence.size(); i++){
            if(searchWord == temp){
                return index;
            }else if(sentence[i] == ' '){
                index++;
                temp = "";
            }else{
                temp += sentence[i];
            }
        }
        if(searchWord == temp){
            return index;
        }
        return -1;
    }
};