class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> diff;
        int i = 0;
        long long gp=0;
        for(int n : nums){
            gp+=diff[n-i];
            diff[n-i]++;
            i++;
        }
        long long n = nums.size();
        long long tp = n*(n-1)/2;
        return tp-gp;

    }
};