class Solution {
public:
    int findFinalValue(vector<int>& v, int og) {
        sort(v.begin(),v.end());
        while(1){
            if(binary_search(v.begin(), v.end(), og)){
                og+=og;
            }
            else return og;
        }
    }
};