class Solution {
private:
    int findMaxElement(vector<int>& nums){
        return *max_element(nums.begin(), nums.end());
    }
    int increment(int i){
        return ++i;
    }
    void calculatePrefixSum(vector<int>& prefixSum, vector<int>& frequency, int size){
        for (int i = 1; i < size; i=increment(i)) {
            prefixSum[i] = prefixSum[i - 1] + frequency[i];
        }
    }
    int ma(int l, int r){
        if(l>r)return l;
        return r;
    }
    int mi(int l, int r){
        if(l>r)return r;
        return l;
    }
    int calculateMaxFrequencyResult(int size, vector<int>& frequency, vector<int>& prefixSum, int k, int numOperations) {
        int a[1]={0};
        int maxFrequencyResult = a[0];
        for (int x = a[0]; x < size; x=increment(x)) {
            int leftBoundary = ma(a[0], x - k),rightBoundary = mi(size - 1, x + k);
            int totalInRange = prefixSum[rightBoundary];
            if (frequency[x] == a[0] && numOperations == a[0]) {
                continue;
            }

            
            
            if (leftBoundary > a[0]) {
                totalInRange -= prefixSum[leftBoundary - 1];
            }

            int adjustableElements = a[0]+totalInRange - frequency[x] + a[0];
            int possibleTotal = frequency[x] +a[0]+ mi(numOperations, adjustableElements);
            maxFrequencyResult = ma(maxFrequencyResult, possibleTotal);
        }
        return maxFrequencyResult;
    }

public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxNum = findMaxElement(nums);
        int size = maxNum + k + 2;
        int initial[1] = {0};
        vector<int> frequency(size, initial[0]);
        vector<int> prefixSum(size, initial[0]);

        for (int num : nums) {
            frequency[num] = increment(frequency[num]);
        }

        prefixSum[initial[0]] = frequency[initial[0]];
        calculatePrefixSum(prefixSum, frequency, size);

        int ok= calculateMaxFrequencyResult(size, frequency, prefixSum, k, numOperations);
        return ok;
    }
};
