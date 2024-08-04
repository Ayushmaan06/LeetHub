class Solution {
public:

    string fun(string s){
        unordered_map<char,int>m;
        int k=1;
        for(auto i:s){
            if(m.find(i)==m.end()){
                m[i]=k++;
            }
        }
        string ref="";
        for(auto i:s){
            // separated int with ','
            ref+=to_string(m[i]+',');
            
        }
        return ref;
    }
     
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        
        string ref=fun(pattern);
        //cout<<ref<<" ";
        vector<string>result;
        
        for(auto str:words){
            //cout<<fun(str)<<" ";
               if(fun(str)==ref){
                   result.push_back(str);
               }   
        }
        return result;

    }
     
    //added ',' at the end while converting char to int
    //["abcdefghijklab","abcdefghijkabl"]
    //"abcdefghijklab"
};