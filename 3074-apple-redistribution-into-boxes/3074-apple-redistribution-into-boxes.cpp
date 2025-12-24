class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        int s = accumulate(a.begin(),a.end(),0),ans=0,x=0;
        sort(c.rbegin(),c.rend());
        for(int i : c){
            ans+=i;
            x++;
            if(ans>=s)return x;
        }
        return -1;
    }
};