class Solution {
public:
    long long C2(int m) {
        long long n = m;
        if (n < 2) {
            return 0;  // Not valid if n < 2
        }
        return (n * (n - 1)) / 2;  // Formula for combinations C(n, 2)
    }
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]-i]++;
        }
        if(m.size()==1)return 0;
        long long s=0;
        for(auto it : m){
            s+= C2(it.second);
        }
        long long t = C2(nums.size());
        return t-s;
    }
};