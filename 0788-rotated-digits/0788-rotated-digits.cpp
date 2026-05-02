class Solution {
public:
    int rotatedDigits(int n) {
        int c=0;
        for(int i = 1 ; i <= n ; i++){
            string s = to_string(i),r;
            bool isp=true;
            for(int j = 0 ; j < s.length(); j++){
                if(s[j] == '3' || s[j] == '4' || s[j] == '7' ){isp=false;break;}
                if(s[j]=='0' || s[j]=='1' || s[j]=='8')r.push_back(s[j]);
                if(s[j] == '2')r.push_back('5');
                if(s[j] == '5')r.push_back('2');
                if(s[j] == '6')r.push_back('9');
                if(s[j] == '9')r.push_back('6');
            }
            if(isp){
                int k = stoi(s), v = stoi(r);
                if(k!=v)c++;
            }
        }
        return c;
    }
};