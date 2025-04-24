class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(50);
        v[1]=1;
        v[2]=2;
        v[3]=3;
        for(int i = 4 ; i < n+1 ; i++){
            v[i]=v[i-1]+v[i-2];
        }
        return v[n];
    }
};