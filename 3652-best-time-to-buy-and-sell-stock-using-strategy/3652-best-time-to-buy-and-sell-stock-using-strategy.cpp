#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> psp(n+1,0),res(n+1,0);
        for (int i = 0; i < n; i++) {
            psp[i+1] = psp[i] + prices[i];
        }
        for(int i = 1 ; i < n+1 ; i++){
            res[i]=(ll)(prices[i-1]*strategy[i-1]) + res[i-1];
        }
        ll ans=res[n];
        for(int i = 0 ; i +k < n + 1; i++){
            ll t=0;
            t+=res[i];
            t+=(psp[i+k]-psp[i+k/2]);
            t+=(res[n]-res[i+k]);
            ans=max(ans,t);
        }
        return ans;
    }
};