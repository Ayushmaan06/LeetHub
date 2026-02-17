class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        string z(10-turnedOn,'0'),o(turnedOn,'1'),s;
        s=z+o;
        vector<string>res;
        do{
            string h = s.substr(0,4), m = s.substr(4,6);
            int hh = stoi(h, nullptr, 2), mm = stoi(m, nullptr, 2);
            if(hh<=11 && mm<=59){
                string hr = to_string(hh),mi=to_string(mm);
                // if(hr.size()<2)hr='0'+hr;
                if(mi.size()<2)mi='0'+mi;
                string x = hr + ":" + mi;
                res.push_back(x);
            }
        }while(next_permutation(s.begin(),s.end()));
        return res;
    }
};