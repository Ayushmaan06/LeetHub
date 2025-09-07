class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)return {0};
        vector<int> res(n);
        for(int i = 0 ; i < n-1 ; i++)res[i]=i+1;
        res[n-1]= -1*((n*(n-1))/2);
        return res;
    }
};