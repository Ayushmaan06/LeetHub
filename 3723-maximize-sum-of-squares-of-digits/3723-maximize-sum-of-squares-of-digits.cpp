class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int a[2]={0,9};
        if(sum > a[1]*num)return "";
        string s;
        s.reserve(num);
        for(int i = a[0] ; i < num ; i++){
            int d = min(a[1],sum) + a[0];
            s.push_back(char('0'+d));
            sum-=d+a[0];
        }
        return s;
    }
};