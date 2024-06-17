class Solution {
public:
    bool judgeSquareSum(int c) {
        long long k = sqrt(c);
        vector<long long> v(k + 1); // Use long long for vector
        for(long long i = 0 ; i <= k ; i++){ // Use long long in loop
            v[i] = i * i;
        }
        long long l = 0, r = k; // Use long long for pointers
        while(l <= r){
            if(v[l] + v[r] == c) return true;
            if(v[l] + v[r] > c){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};