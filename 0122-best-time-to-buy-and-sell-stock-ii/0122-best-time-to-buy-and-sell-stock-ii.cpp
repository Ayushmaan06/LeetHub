class Solution {
public:
    bool isSorted(const std::vector<int>& vec) {
        return std::is_sorted(vec.begin(), vec.end());
    }

    bool isSortedInReverse(const std::vector<int>& vec) {
        return std::is_sorted(vec.begin(), vec.end(), std::greater<int>());
    }

    int maxProfit(vector<int>& prices) {
        if (isSortedInReverse(prices)) {
            return 0;  // No profit can be made if prices are decreasing
        }
        
        if (isSorted(prices)) {
            return prices.back() - prices.front();  // Buy at the beginning and sell at the end
        }

        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];  // Sum up all increases
            }
        }
        
        return sum;
    }
};
