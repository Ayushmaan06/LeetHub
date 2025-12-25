#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        priority_queue<int> pq;
        for(int i : h)pq.push(i);
        ll ans=0,n=0;
        while(k--){
            ll t=pq.top()-n;
            t=max(t,0LL);
            if(t==0)return ans;
            pq.pop();
            n++;
            ans+=t;
        }
        return ans;
    }
};