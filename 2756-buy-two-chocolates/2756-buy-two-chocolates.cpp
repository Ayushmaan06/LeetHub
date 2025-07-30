class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int i1=prices[0],i2=prices[1];
        if(i1+i2<=money)money-=i1+i2;
        return money;
    }
};