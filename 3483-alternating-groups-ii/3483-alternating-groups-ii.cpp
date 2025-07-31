class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& col, int k) {
        int n = col.size();
        int sz=n+k;
        int prev=col[0];
        int alt=0;
        int ans=0;
        for(int i = 1 ; i < sz ; i++){
            if(prev!=col[i%n])alt++;
            else{
                alt=1;
            }
            prev=col[i%n];
            if(alt>=k)ans++;
        }
        return ans;
    }  
};