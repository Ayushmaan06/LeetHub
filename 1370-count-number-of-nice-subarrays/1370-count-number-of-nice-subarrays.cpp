class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> sumCount;
        int a=1,b=0;
        sumCount[0] = 1;
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            if(num%2==0)    sum+=b;
            else            sum+=a;
            
            if (sumCount.count(sum - k)) {
                count += sumCount[sum - k];
            }
            sumCount[sum]++;
        }
        return count;
    }
};
