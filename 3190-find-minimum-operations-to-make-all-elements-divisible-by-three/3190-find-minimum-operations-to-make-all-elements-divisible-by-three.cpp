class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int a=0;
        for(int n : nums)a+=min(n%3 , 3 - (n%3));
        return a;
    }
};