class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> og(n,0);
        for(int i = 0 ; i < n-1 ; i++){
            if(derived[i]==0){
                og[i+1]=og[i];
            }
            else{
                og[i+1]=og[i]^1;
            }
        }
        if(derived[n-1]==1){
            if(og[n-1]==og[0])return false;
        }
        else{
            if(og[n-1]!=og[0])return false;
        }
        return true;
    }
};