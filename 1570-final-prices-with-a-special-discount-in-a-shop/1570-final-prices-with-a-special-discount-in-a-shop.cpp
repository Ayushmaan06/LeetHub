class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }

            if (!s.empty()) {
                result[i] = nums[s.top()];
            }
            else{
                result[i]=0;
            }
            s.push(i);
        }

        return result;
    }
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ns=nextSmallerElements(prices);
        for(int i=0 ; i<prices.size() ; i++){
            prices[i]-=ns[i];
        }
        return prices;
    }
};