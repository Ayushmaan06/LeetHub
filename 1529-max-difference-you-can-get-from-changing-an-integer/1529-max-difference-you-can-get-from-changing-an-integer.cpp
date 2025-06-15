class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string ma = "";
        string mi = "";
        int n = str.size();
        char ele = ' ';
        for(int i=0;i<n;i++){
            if(str[i] != '9'){
                ele = str[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(ele == str[i]) ma += '9';
            else ma += str[i];
        }
        char ele1 = ' ';
        char c = '1' ;
        for(int i=0;i<n;i++){
            if(str[i] != '1'&& i==0){
                ele1 = str[i];
                c='1';
                break;
            }
            if(str[i]!='0' && i>0 && str[i]!=str[0]){
                ele1 = str[i];
                c='0';
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(ele1 == str[i]) mi += c;
            else mi += str[i];
        }
        
        return stoi(ma) - stoi(mi);
    }
};