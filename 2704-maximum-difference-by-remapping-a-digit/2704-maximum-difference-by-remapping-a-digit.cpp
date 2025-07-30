class Solution {
public:
    int minMaxDifference(int num) {
        string nn=to_string(num);
        string ma="",mi="";
        int n = nn.length();
        int i=0;
        while(i<n && nn[i]=='9'){
            i++;
        }
        if(i>=n)ma=nn;
        else{
            char c=nn[i];
            for(char cc : nn){
                if(cc==c)ma+='9';
                else ma+=cc;
            }
        }
        i=0;
        while(i<n && nn[i]=='0'){
            i++;
        }
        if(i>=n)mi=nn;
        else{
            char c=nn[i];
            for(char cc : nn){
                if(cc==c)mi+='0';
                else mi+=cc;
            }
        }
        return (stoi(ma)-stoi(mi));

    }
};