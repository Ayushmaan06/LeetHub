class Solution {
public:
    long nCr(int n, int r) {
        if (r > n) return 0;
        long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productCount;
        
        // Count all the products of pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }
        
        int result = 0;
        // For each product, calculate the number of valid quadruples
        for (auto& entry : productCount) {
            int count = entry.second;
            if (count > 1) {
                result += (nCr(count, 2) * 4);  // each valid pair can contribute 4 valid quadruples
            }
        }
        
        return result*2;
    }
};
