class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> og(n,0);
        for(int i = 0 ; i < n-1 ; i++){
            if(derived[i])og[i+1]=og[i]^1;
            else{
                og[i+1]=og[i];
            }
        }
        return ((og[n-1]^og[0])==derived[n-1]);
    }
};