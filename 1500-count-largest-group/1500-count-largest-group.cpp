class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> freq(37, 0);  
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            freq[sum]++;
        }
        
        int maxSize = *max_element(freq.begin(), freq.end());
        int count = count_if(freq.begin(), freq.end(), [maxSize](int x) {
            return x == maxSize;
        });
        
        return count;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
