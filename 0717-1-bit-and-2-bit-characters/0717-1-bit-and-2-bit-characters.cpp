class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(),i=0;
        for( ; i < n-1 ; i++){
            if(bits[i])i++;
        }
        // cout<<i;
        return (i==n-1);
    }
};